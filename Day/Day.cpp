#include <iostream>
using namespace std;
typedef long long LL;

const LL SY = 40;
const LL SCY = 30 * SY;
const LL SG = 20 * SCY;
const LL SCE = 12 * SG;
const LL SE = 5 * SCE;

const LL QH = 1;
const LL QS = 35 * QH;
const LL QM = 25 * QS;
const LL QL = 15 * QM;

const LL MD = 1;
const LL MC = 32 * MD;
const LL ME = 22 * MC;
const LL MEP = 18 * ME;

LL csd(LL se, LL sce, LL sg, LL scy, LL sy) {
    LL td = (se - 1) * SE + (sce - 1) * SCE + (sg - 1) * SG + (scy - 1) * SCY + (sy - 1) * SY;
    if (se % 5 == 0 && sce == 10 && sg == 10 && scy == 20) td += 10;
    if (se % 7 == 0) td -= 2;
    return td;
}

void ctq(LL td, ostream& out) {
    LL qlc = td / QL + 1;
    td %= QL;
    LL qmc = td / QM + 1;
    td %= QM;
    LL qsc = td / QS + 1;
    td %= QS;
    LL qh = td + 1;
    cout << qlc << " " << qmc << " " << qsc << " " << qh << "\n";
}

void ctm(LL td, ostream& out) {
    LL mep = td / MEP + 1;
    td %= MEP;
    LL me = td / ME + 1;
    td %= ME;
    LL mc = td / MC + 1;
    td %= MC;
    LL md = td + 1;
    cout << mep << " " << me << " " << mc << " " << md << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        LL se, sce, sg, scy, sy;
        cin >> se >> sce >> sg >> scy >> sy;
        LL td = csd(se, sce, sg, scy, sy);
        ctq(td, cout);
        ctm(td, cout);
    }
    return 0;
}    