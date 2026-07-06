#include <bits/stdc++.h>
using namespace std;

struct Pig {
    char role;              // M Z F
    int reveal;             // 0 unknown, 1 loyal, 2 rebel
    bool suspect;           // only meaningful for MP's judgement
    int hp;
    bool alive;
    bool zhuge;
    vector<char> hand;
};

int n, m;
vector<Pig> a;
vector<char> deck;
int deckPos = 0;
string winner;

char drawOne() {
    if (deckPos < (int)deck.size()) return deck[deckPos++];
    return deck.back();
}

void drawCards(int x, int cnt) {
    for (int i = 0; i < cnt; ++i) a[x].hand.push_back(drawOne());
}

int nextAlive(int x) {
    int y = x % n + 1;
    while (!a[y].alive) y = y % n + 1;
    return y;
}

bool checkWin() {
    if (!a[1].alive) {
        winner = "FP";
        return true;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i].alive && a[i].role == 'F') return false;
    }
    winner = "MP";
    return true;
}

int findCard(int x, char c) {
    for (int i = 0; i < (int)a[x].hand.size(); ++i) {
        if (a[x].hand[i] == c) return i;
    }
    return -1;
}

bool removeFirstCard(int x, char c) {
    int p = findCard(x, c);
    if (p == -1) return false;
    a[x].hand.erase(a[x].hand.begin() + p);
    return true;
}

void revealAs(int x, int side) {
    if (x == 1) return;
    a[x].reveal = side;
    a[x].suspect = false;
}

bool isLoyalKnown(int x) {
    return x == 1 || a[x].reveal == 1;
}

bool isRebelKnown(int x) {
    return a[x].reveal == 2;
}

bool canAid(int who, int target) {
    if (!a[who].alive || findCard(who, 'J') == -1) return false;
    if (who == 1) return isLoyalKnown(target);
    if (a[who].role == 'Z') return isLoyalKnown(target);
    return isRebelKnown(target);
}

bool canHostile(int who, int target) {
    if (!a[who].alive || findCard(who, 'J') == -1) return false;
    if (who == 1) return isRebelKnown(target);
    if (a[who].role == 'Z') return isRebelKnown(target);
    return isLoyalKnown(target);
}

void markHostileAction(int who, int target) {
    if (who == 1) return;
    if (target == 1 || a[target].reveal == 1) revealAs(who, 2);
    else if (a[target].reveal == 2) revealAs(who, 1);
}

bool nullifyChain(int start, int target, bool aidAction) {
    int cur = start;
    do {
        if (a[cur].alive) {
            bool ok = aidAction ? canAid(cur, target) : canHostile(cur, target);
            if (ok) {
                removeFirstCard(cur, 'J');
                if (aidAction) {
                    if (isLoyalKnown(target)) revealAs(cur, 1);
                    else if (isRebelKnown(target)) revealAs(cur, 2);
                } else {
                    if (isLoyalKnown(target)) revealAs(cur, 2);
                    else if (isRebelKnown(target)) revealAs(cur, 1);
                }
                return !nullifyChain(cur, target, !aidAction);
            }
        }
        cur = cur % n + 1;
    } while (cur != start);
    return false;
}

bool trySaveWithPeach(int x) {
    while (a[x].hp <= 0) {
        int p = findCard(x, 'P');
        if (p == -1) return false;
        a[x].hand.erase(a[x].hand.begin() + p);
        ++a[x].hp;
    }
    return true;
}

void clearAllCards(int x) {
    a[x].hand.clear();
    a[x].zhuge = false;
}

void killPig(int dead, int killer) {
    a[dead].alive = false;
    clearAllCards(dead);
    if (checkWin()) return;
    if (a[dead].role == 'F') {
        if (killer >= 1 && killer <= n && a[killer].alive) drawCards(killer, 3);
    } else if (a[dead].role == 'Z') {
        if (killer == 1) clearAllCards(1);
    }
}

void damage(int src, int dst) {
    --a[dst].hp;
    if (a[dst].hp > 0) return;
    if (trySaveWithPeach(dst)) return;
    killPig(dst, src);
}

bool targetForHostility(int who, int target) {
    if (!a[target].alive || who == target) return false;
    if (who == 1) return a[target].reveal == 2 || a[target].suspect;
    if (a[who].role == 'Z') return a[target].reveal == 2;
    if (target == 1) return true;
    return a[target].reveal == 1;
}

int firstTargetForKill(int who) {
    int t = nextAlive(who);
    if (t == who) return 0;
    return targetForHostility(who, t) ? t : 0;
}

int firstTargetForDuel(int who) {
    if (a[who].role == 'F' && a[1].alive && who != 1) return 1;
    int cur = who % n + 1;
    while (cur != who) {
        if (targetForHostility(who, cur)) return cur;
        cur = cur % n + 1;
    }
    return 0;
}

bool respondKill(int x) {
    int p = findCard(x, 'D');
    if (p == -1) return false;
    a[x].hand.erase(a[x].hand.begin() + p);
    return true;
}

bool respondAoeNeedKill(int x) {
    int p = findCard(x, 'K');
    if (p == -1) return false;
    a[x].hand.erase(a[x].hand.begin() + p);
    return true;
}

bool respondAoeNeedDodge(int x) {
    int p = findCard(x, 'D');
    if (p == -1) return false;
    a[x].hand.erase(a[x].hand.begin() + p);
    return true;
}

bool duelCanPlayKill(int x, int opp) {
    if (a[x].role == 'Z' && opp == 1) return false;
    return findCard(x, 'K') != -1;
}

void useKill(int who, int target, bool &usedKill) {
    removeFirstCard(who, 'K');
    usedKill = true;
    markHostileAction(who, target);
    if (respondKill(target)) return;
    damage(who, target);
}

void useDuel(int who, int target) {
    removeFirstCard(who, 'F');
    markHostileAction(who, target);
    if (nullifyChain(who, target, true)) return;
    int cur = target, opp = who;
    while (true) {
        if (!a[cur].alive || !a[opp].alive) return;
        if (!duelCanPlayKill(cur, opp)) {
            damage(opp, cur);
            return;
        }
        removeFirstCard(cur, 'K');
        swap(cur, opp);
    }
}

void useAoe(int who, char type) {
    removeFirstCard(who, type);
    int cur = who;
    for (int step = 1; step < n; ++step) {
        cur = nextAlive(cur);
        if (cur == who) break;
        if (!a[cur].alive) continue;
        if (nullifyChain(who, cur, true)) continue;
        bool defended = (type == 'N' ? respondAoeNeedKill(cur) : respondAoeNeedDodge(cur));
        if (!defended) {
            damage(who, cur);
            if (!winner.empty()) return;
            if (cur == 1 && a[who].alive && a[who].reveal == 0) a[who].suspect = true;
        }
        if (!a[who].alive) return;
    }
}

void equipZ(int who) {
    removeFirstCard(who, 'Z');
    a[who].zhuge = true;
}

void usePeach(int who) {
    removeFirstCard(who, 'P');
    ++a[who].hp;
}

void playTurn(int who) {
    if (!a[who].alive) return;
    drawCards(who, 2);
    bool usedKill = false;
    while (a[who].alive && winner.empty()) {
        bool moved = false;
        for (int i = 0; i < (int)a[who].hand.size(); ++i) {
            char c = a[who].hand[i];
            if (c == 'P') {
                if (a[who].hp < 4) {
                    usePeach(who);
                    moved = true;
                    break;
                }
            } else if (c == 'Z') {
                equipZ(who);
                moved = true;
                break;
            } else if (c == 'N' || c == 'W') {
                useAoe(who, c);
                moved = true;
                break;
            } else if (c == 'K') {
                if ((!usedKill || a[who].zhuge)) {
                    int t = firstTargetForKill(who);
                    if (t) {
                        useKill(who, t, usedKill);
                        moved = true;
                        break;
                    }
                }
            } else if (c == 'F') {
                int t = firstTargetForDuel(who);
                if (t) {
                    useDuel(who, t);
                    moved = true;
                    break;
                }
            }
            if (!a[who].alive || !winner.empty()) break;
        }
        if (!moved) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.assign(n + 1, {});
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        a[i].role = s[0];
        a[i].reveal = (i == 1 ? 1 : 0);
        a[i].suspect = false;
        a[i].hp = 4;
        a[i].alive = true;
        a[i].zhuge = false;
        for (int j = 0; j < 4; ++j) {
            cin >> s;
            a[i].hand.push_back(s[0]);
        }
    }
    deck.resize(m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        deck[i] = s[0];
    }

    int cur = 1;
    while (winner.empty()) {
        if (a[cur].alive) playTurn(cur);
        if (!winner.empty()) break;
        cur = cur % n + 1;
    }

    cout << winner << '\n';
    for (int i = 1; i <= n; ++i) {
        if (!a[i].alive) {
            cout << "DEAD\n";
            continue;
        }
        for (int j = 0; j < (int)a[i].hand.size(); ++j) {
            if (j) cout << ' ';
            cout << a[i].hand[j];
        }
        cout << '\n';
    }
    return 0;
}
