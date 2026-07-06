#pragma once
#include<iostream>
#include<vector>
#include<stack>
#define LIntegerYMax 1000000000
class LIntegerY;
std::ostream& operator <<(std::ostream& out, LIntegerY& Out);
std::istream& operator >>(std::istream& in, LIntegerY& In);
class LIntegerY {
private:
    std::vector<int> Number;
    void LeftBig()
    {
        this->Number.insert(this->Number.begin(), 0);
    }
    void RightLittle()
    {
        this->Number.erase(this->Number.begin());
    }
public:
    LIntegerY(std::vector<int> number)
    {
        this->Number = number;
    }
    LIntegerY()
    {
        this->Number.push_back(0);
    }
    LIntegerY(int num)
    {
        this->Number.push_back(num);
    }
    void operator =(LIntegerY Another)
    {
        this->Number = Another.Number;
    }
    LIntegerY operator +(LIntegerY Another)
    {
        LIntegerY Back;
        Back.Number.clear();
        std::vector<int>::iterator find1 = this->Number.begin();
        std::vector<int>::iterator find2 = Another.Number.begin();
        int jinwei = 0, benwei = 0;
        while (find1 != this->Number.end() && find2 != Another.Number.end())
        {
            benwei = jinwei + *find1 + *find2;
            if (benwei >= LIntegerYMax)
            {
                benwei -= LIntegerYMax;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            Back.Number.push_back(benwei);
            find1++;
            find2++;
        }
        while (find1 != this->Number.end())
        {
            benwei = jinwei + *find1;
            if (benwei >= LIntegerYMax)
            {
                benwei -= LIntegerYMax;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            Back.Number.push_back(benwei);
            find1++;
        }
        while (find2 != Another.Number.end())
        {
            benwei = jinwei + *find2;
            if (benwei >= LIntegerYMax)
            {
                benwei -= LIntegerYMax;
                jinwei = 1;
            }
            else
            {
                jinwei = 0;
            }
            Back.Number.push_back(benwei);
            find2++;
        }
        return Back;
    }
    
    LIntegerY operator * (LIntegerY Another)
    {
        std::vector<LIntegerY> Line;
        int id = 0;
        for (auto find1 : this->Number)
        {
            LIntegerY EditLine;
            EditLine.Number.clear();
            long long Find1 = (long long)(find1);
            int jinwei = 0, benwei = 0;
            for (auto find2 : Another.Number)
            {
                long long Find2 = (long long)(find2);
                long long Result = Find1 * Find2 + jinwei;
                benwei = Result % LIntegerYMax;
                jinwei = Result / LIntegerYMax;
                EditLine.Number.push_back(benwei);
            }
            if (jinwei > 0)
                EditLine.Number.push_back(jinwei);
            for (int i = 0; i < id; i++)
                EditLine.LeftBig();
            id++;
            Line.push_back(EditLine);
        }
        LIntegerY Back;
        for (auto find : Line)
        {
            Back = Back + find;
        }
        return Back;
    }
    
    friend std::ostream& operator <<(std::ostream& out, LIntegerY& Out);
    friend std::istream& operator >>(std::istream& in, LIntegerY& In);
};
 
LIntegerY operator *(int A,LIntegerY B)
{
    return (LIntegerY(A))*B;
}
 
std::ostream& operator <<(std::ostream& out, LIntegerY& Out)
{
    std::stack<int> Stack;
    for (auto find : Out.Number)
    {
        Stack.push(find);
    }
    int Getout = 0;
    bool First = true;
    while (!Stack.empty())
    {
        Getout = Stack.top();
        int wei = 0;
        while (Getout > 0)
        {
            wei++;
            Getout /= 10;
        }
        if (!First)
        {
            for (int i = 0; i < 9 - wei; i++)
                out << "0";
        }
        First = false;
        Getout = Stack.top();
        if(Getout>0)
            out << Getout;
        Stack.pop();
    }
    return out;
}
 
std::istream& operator >>(std::istream& in, LIntegerY& In)
{
    std::string s;
    std::cin >> s;
    In.Number.clear();
    while (!s.empty())
    {
        int wei = 0;
        int benwei = 0;
        while (wei < 9 && !s.empty())
        {
            benwei += ((int)(s.back()) - (int)('0')) * pow(10, wei);
            s.pop_back();
            wei++;
        }
        In.Number.push_back(benwei);
    }
    return in;
}
