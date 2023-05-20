#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class half;
class winprediction;
class player
{
    int ball, baavg, bwick, bwavg, btwavg;
    friend class winprediction;
    friend class wicketprediction;
    friend class prediction;
public:
    void wickets()
    {
        cout << "Enter the number of wickets fallen in 6 overs ";
        cin >> ball;
        cout << "Enter number of average wickets fallen in previous matches by the team ";
        cin >> baavg;
        cout << "Enter the wickets taken in most mathes in first 6 overs ";
        cin >> bwick;
        cout << "Enter the wickets taken in most matches ";
        cin >> bwavg;
        cout << "Enter the wickets takem by most of the teams ";
        cin >> btwavg;
    }
};
class teamhistroy
{
    double runrate, avgrr;
    int avg1, avg2;
    friend class winprediction;
    friend class wicketprediction;
    friend class prediction;
public:
    void condition()
    {
        cout << "Enter the average runs scored by most teams in current pitch ";
        cin >> avg1;
        cout << "Enter the average runs scored by team in previous matches ";
        cin >> avg2;
        cout << "Enter the runrate at 6 overs ";
        cin >> runrate;
        cout << "Enter average runrate in previous matches of team ";
        cin >> avgrr;
    }
};
class over
{
    int o, n4, n5;
    double o1;
    friend class winprediction;
    friend class wicketprediction;
    friend class prediction;
    friend class half;
    friend class team;
public:
    void runs()
    {
        cout << "Enter runs scored by first 6 overs ";
        cin >> o;
        cout << "Enter the matches played in current year by batting team ";
        cin >> n4;
        cout << "Enter the natches played in current year by balling team ";
        cin >> n5;
        if (n4 != 0)
        {
            cout << "Enter the average runs scored by team in first 6 overs in previous matches ";
            cin >> o1;
        }
    }
};
class team
{
    string t, t1, tw;
    int n, n1, win, win1, loss, sc, n3, i, tp, p1, p2, rr, rr1;
    over f;
    // team s;
    double avg;
    friend class winprediction;
    friend class wicketprediction;
    friend class prediction;
    friend class half;
public:
    void teamname()
    {
        // s.code();
        cout << "Enter the name of batting team ";
        cin >> t;
        cout << "Enter the name of balling team ";
        cin >> t1;
    }
    void position()
    {
        if ((f.n4 >= 3 && f.n5 >= 3) || (f.n4 >= 2 && f.n5 >= 3) || (f.n4 >= 3 && f.n5 >= 2))
        {
            cout << "Enter the position of team " << t << "in points table ";
            cin >> p1;
            cout << "Enter the position of team " << t1 << "in points table ";
            cin >> p2;
            cout << "Enter the net runrate on points table of team " << t;
            cin >> rr;
            cout << "Enter the net runrate on points table of team " << t1;
            cin >> rr1;
        }
    }
    void wincriteria()
    {
        cout << "total number of matches did batting team played ";
        cin >> n;
        cout << "total number of matches did balling team played ";
        cin >> n1;
        cout << "Enter the name of toss winning team ";
        cin >> tw;
        cout << "Enter the number of matches played by teams against each other ";
        cin >> tp;
    }
    void performance()
    {
        int a[n3];
        cout << "Enter number of matches played against each other previously ";
        cin >> n3;
        if (n3 > 0)
        {
            for (i = 0; i < n3; i++)
            {
                cin >> a[i];
            }
            for (i = 0; i < n3; i++)
            {
                avg = a[i];
            }
        }
        else
        {
            cout << "No matches played previously " << endl;
        }
    }
};
// class teamcode
//{
//     public:
//     int code()
//     {
//         cout<<"code '1', team is 'GT'"<<endl;
//         cout<<"code '2', team is 'CSK'"<<endl;
//         cout<<"code '3', team is 'LSG'"<<endl;
//         cout<<"code '4', team is 'DC'"<<endl;
//         cout<<"code '5', team is 'RR'"<<endl;
//         cout<<"code '6', team is 'SRH'"<<endl;
//         cout<<"code '7', team is 'MI'"<<endl;
//         cout<<"code '8', team is 'RCB'"<<endl;
//     }
// };
class prediction
{
    int i, cnt = 0;
public:
    void predicts(player a, teamhistroy t, over o);
};
//member of class prediction.
void prediction::predicts(player a, teamhistroy t, over o)
{
    {
        cout << "Predicted score according to runrate " << (t.runrate * 20) << endl;
        while (cnt <= 3)
        {
            static int i = t.runrate; // check that static doen't take value zero
            cout << "Score if runrate is " << i << " = " << (i * 20) << endl;
            i++;
            cnt++;
        }
        if (o.n4 >= 3)
        {
            if (t.avg2 >= 171)
            {
                if (a.ball >= 4)
                {
                    cout << "Predicted score by wickets is " << (t.avg2 - 10) << endl;
                }
                else if (a.ball == 2)
                {
                    cout << "Predicted score by wickets is " << (t.avg2 + 13) << endl;
                }
                else if (a.ball == 3)
                {
                    cout << "Predicted score by wickets is " << t.avg2 << endl;
                }
                else if (a.ball <= 1)
                {
                    cout << "Predicted score by wickets is " << (t.avg2 + 24) << endl;
                }
            }
            else
            {
                if (a.ball >= 4){
                    cout << "Predicted score by wickets is " << (t.avg2 - 19) << endl;
                }
                else if (a.ball == 3){
                    cout << "Predicted score by wickets is " << t.avg2 << endl;
                }
                else if (a.ball == 2){
                    cout << "Predicted score by wickets is " << (t.avg2 + 6) << endl;
                }
                else if (a.ball == 1){
                    cout << "Predicted score by wickets is " << (t.avg2 + 15) << endl;
                }
                else{
                    cout << "Predicted score by wickets is " << (t.avg2 + 23) << endl;
                }
            }
        }
        else if (o.n4 >= 0 || o.n4 <= 2)
        {
            if (a.ball >= 4)
            {
                cout << "Predicted score by wickets is " << (t.avg1 - 15) << endl;
            }
            else if (a.ball == 3)
            {
                cout << "Predicted score by wickets is " << t.avg1 << endl;
            }
            else if (a.ball == 2)
            {
                cout << "Predicted score by wickets is " << (t.avg1 + 9) << endl;
            }
            else if (a.ball == 1)
            {
                cout << "Predicted score by wickets is " << (t.avg1 + 18) << endl;
            }
            else
            {
                cout << "Predicted score by wickets is " << (t.avg1 + 26) << endl;
            }
        }
    }
}
class wicketprediction
{
public:
    void wicketpredicts(player a, over o);
};
// member of class wicket prediction.
void wicketprediction::wicketpredicts(player a, over o)
{
    if (o.n4 >= 3)
    {
        if (a.bwavg >= 6)
        {
            if (a.ball >= 4)
            {
                cout << "predicted wickets will be 10" << endl;
            }
            else if (a.ball == 3)
            {
                cout << "predicted wickets will 8 " << endl;
            }
            else if (a.ball == 2)
            {
                cout << "predicted wickets will be " << a.bwavg << endl;
            }
            else if (a.ball <= 1)
            {
                cout << "preidcted wickets will be " << (a.bwavg - 2) << endl;
            }
        }
        else
        {
            if (a.ball >= 4)
            {
                cout << "predicted wickets will be 10" << endl;
            }
            else if (a.ball == 3)
            {
                cout << "predicted wickets will 7 " << endl;
            }
            else if (a.ball == 2)
            {
                cout << "predicted wickets will be " << a.bwavg << endl;
            }
            else if (a.ball <= 1)
            {
                cout << "preidcted wickets will be " << (a.bwavg - 1) << endl;
            }
        }
    }
    else if (o.n4 >= 0 || o.n4 <= 2)
    {
        if (a.ball >= 4)
        {
            cout << "predicted wickets will be 10" << endl;
        }
        else if (a.ball == 3)
        {
            cout << "predicted wickets will 8 " << endl;
        }
        else if (a.ball == 2)
        {
            cout << "predicted wickets will be " << a.btwavg << endl;
        }
        else if (a.ball <= 1)
        {
            cout << "preidcted wickets will be " << (a.btwavg - 2) << endl;
        }
    }
}
class half
{
    int i,c;
public:
    void halfpredict(over s, team n);
};
//member of class half.
void half ::halfpredict(over s, team n)
{
    cout<< "Enter the number of matches played by team against each other ";
    cin>>i;
    if (i != 0)
        {
            if (i >= 2)
            {
                cout << "Enter the '1' if toss winning  team won most times ";
                cout << "Enter the '2' if toss lossing team won most times ";
                cout << "Enter the '3' if both team won equally ";
                cin >> c;
            }
        }
    if ((s.n4 >= 3 && s.n5 >= 3) || (s.n4 >= 2 && s.n5 >= 3) || (s.n4 >= 3 && s.n5 >= 2))
    {
        if (i >= 2 && c == 1)
        {
            cout << "Winning percentage of team " << n.t << "is 85%";
            cout << "Winning percentage of team " << n.t1 << "is 15% ";
        }
        else if (i >= 2 && c == 2)
        {
            cout << "Winning percentage of team " << n.t << "is 15% ";
            cout << "Winning percentage of team " << n.t1 << "is 85% ";
        }
        else if (i >= 2 && c == 3)
        {
            if (n.rr > n.rr1)
            {
                cout << "Winning percentage of team " << n.t << "is 55% ";
                cout << "Winning percentage of team " << n.t1 << "is 45% ";
            }
            else if (n.rr < n.rr1)
            {
                cout << "Winning percentage of team " << n.t << "is 45% ";
                cout << "Winning percentage of team " << n.t1 << "is 55% ";
            }
            else if (n.rr == n.rr1)
            {
                if (n.p2 + 1 == n.p1 || n.p2 == n.p1 + 1)
                {
                    if (!n.t.compare(n.tw))
                    {
                        cout << "Winning percentage of team " << n.t << "is 55% ";
                        cout << "Winning percentage of team " << n.t1 << "is 45% ";
                    }
                    else if (!n.t1.compare(n.tw))
                    {
                        cout << "Winning percentage of team " << n.t << "is 45% ";
                        cout << "Winning percentage of team " << n.t1 << "is 55% ";
                    }
                }
                else if (n.p1 + 2 >= n.p2)
                {
                    cout << "Winning percentage of team " << n.t << "is 58% ";
                    cout << "Winning percentage of team " << n.t1 << "is 42% ";
                }
                else if (n.p1 <= n.p2 + 2)
                {
                    cout << "Winning percentage of team " << n.t << "is 42% ";
                    cout << "Winning percentage of team " << n.t1 << "is 58% ";
                }
            }
        }
        else if (i < 2)
        {
            if (n.p2 + 1 == n.p1 || n.p2 == n.p1 + 1)
            {
                if (!n.t.compare(n.tw))
                {
                    cout << "Winning percentage of team " << n.t << "is 55% ";
                    cout << "Winning percentage of team " << n.t1 << "is 45% ";
                }
                else if (!n.t1.compare(n.tw))
                {
                    cout << "Winning percentage of team " << n.t << "is 45% ";
                    cout << "Winning percentage of team " << n.t1 << "is 55% ";
                }
            }
            else if (n.p1 + 2 >= n.p2)
            {
                cout << "Winning percentage of team " << n.t << "is 58% ";
                cout << "Winning percentage of team " << n.t1 << "is 42% ";
            }
            else if (n.p1 <= n.p2 + 2)
            {
                cout << "Winning percentage of team " << n.t << "is 42% ";
                cout << "Winning percentage of team " << n.t1 << "is 58% ";
            }
        }
    }
    else
    {
        if (!n.t.compare(n.tw))
        {
            cout << "Winning percentage of team " << n.t << "is 55% ";
            cout << "Winning percentage of team " << n.t1 << "is 45% ";
        }
        else if (!n.t1.compare(n.tw))
        {
            cout << "Winning percentage of team " << n.t << "is 45% ";
            cout << "Winning percentage of team " << n.t1 << "is 55% ";
        }
    }
}
class winprediction
{
    int w1, w2, win1, win2, r, r1, wr;
    friend class half;
public:
    void winpredicts(team x, over s, player y, half m);
};
//member of class winprediction
void winprediction ::winpredicts(team x, over s, player y, half m)
{
        // cout<<"If the team win the toss there is 40% more chances that the team will win";
        cout << "Enter the winning percentage in current year of team  " << x.t << "in total matches played previous this year";
        cin >> w1;
        cout << "Enter the winning percentage in current year of team  " << x.t1 << "in total matches played previous this year";
        cin >> w2;
        cout << "Enter the runs scored by the first batting team in first 6 overs ";
        cin >> r;
        cout << "Enter the wickets fallen by the first batting team in first 6 overs ";
        cin >> wr;
        cout << "Enter the runs scored by the batting team in 20 overs ";
        cin >> r1; 
        /* ********* MAIN PREDICTIION *********** */
        if (r1 > 205 && ((r - s.o) <= -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 92% ";
                cout << "Winning percentage of team " << x.t1 << "is 8% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 82% ";
                cout << "Winning percentage of team " << x.t1 << "is 18% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is 97% ";
                cout << "Winning percentage of team " << x.t1 << "is 3% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 78% ";
                cout << "Winning percentage of team " << x.t1 << "is 22% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 80% ";
                cout << "Winning percentage of team " << x.t1 << "is 20% ";
            }
        }
        else if ((r1 > 205) && ((r - s.o) >= 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 92% ";
                cout << "Winning percentage of team " << x.t1 << "is 8% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 89% ";
                cout << "Winning percentage of team " << x.t1 << "is 11% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 79% ";
                cout << "Winning percentage of team " << x.t1 << "is 21% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 87% ";
                cout << "Winning percentage of team " << x.t1 << "is 13% ";
            }
        }
        else if ((r1 <= 205 && r1 > 185) && ((r - s.o) <= -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 90% ";
                cout << "Winning percentage of team " << x.t1 << "is 10% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 83% ";
                cout << "Winning percentage of team " << x.t1 << "is 17% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  95% ";
                cout << "Winning percentage of team " << x.t1 << "is 5% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 69% ";
                cout << "Winning percentage of team " << x.t1 << "is 31% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 85% ";
                cout << "Winning percentage of team " << x.t1 << "is 15% ";
            }
        }
        else if ((r1 <= 205 && r1 > 185) && ((r - s.o) >= 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 90% ";
                cout << "Winning percentage of team " << x.t1 << "is 10% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 82% ";
                cout << "Winning percentage of team " << x.t1 << "is 18% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  96% ";
                cout << "Winning percentage of team " << x.t1 << "is 4% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 81% ";
                cout << "Winning percentage of team " << x.t1 << "is 19% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 85% ";
                cout << "Winning percentage of team " << x.t1 << "is 15% ";
            }
        }
        else if ((r1 <= 185 && r1 >= 169) && ((r - s.o) <= -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 62% ";
                cout << "Winning percentage of team " << x.t1 << "is 37% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 55% ";
                cout << "Winning percentage of team " << x.t1 << "is 45% ";
                // by points rtable or by toss win prpbability ;
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  69% ";
                cout << "Winning percentage of team " << x.t1 << "is 31% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 47% ";
                cout << "Winning percentage of team " << x.t1 << "is 53% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 <= 185 && r1 >= 169) && ((r - s.o) >= 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 65% ";
                cout << "Winning percentage of team " << x.t1 << "is 35% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 55% ";
                cout << "Winning percentage of team " << x.t1 << "is45% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  70% ";
                cout << "Winning percentage of team " << x.t1 << "is 30% ";
            }
            else if ((wr - y.ball) > 2)
            {
                m.halfpredict(s,x);
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 60% ";
                cout << "Winning percentage of team " << x.t1 << "is 40% ";
                // check by toss and points table.
            }
        }
        else if ((r1 <= 168 && r1 >= 150) && ((r - s.o) <= -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 45% ";
                cout << "Winning percentage of team " << x.t1 << "is 55% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 40% ";
                cout << "Winning percentage of team " << x.t1 << "is 60% ";
            }
            else if ((wr - y.ball) < -2)
            {
                m.halfpredict(s,x);
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is  30% ";
                cout << "Winning percentage of team " << x.t1 << "is 70% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 < 149) && ((r - s.o) >= 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 40% ";
                cout << "Winning percentage of team " << x.t1 << "is 60% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 31% ";
                cout << "Winning percentage of team " << x.t1 << "is 69% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  45% ";
                cout << "Winning percentage of team " << x.t1 << "is 55% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 25% ";
                cout << "Winning percentage of team " << x.t1 << "is 75% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 25% ";
                cout << "Winning percentage of team " << x.t1 << "is 75% ";
            }
        }
        else if ((r1 < 149) && ((r - s.o) <= -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 40% ";
                cout << "Winning percentage of team " << x.t1 << "is 60% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 10% ";
                cout << "Winning percentage of team " << x.t1 << "is 90% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  42% ";
                cout << "Winning percentage of team " << x.t1 << "is 58% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 5% ";
                cout << "Winning percentage of team " << x.t1 << "is 95% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 20% ";
                cout << "Winning percentage of team " << x.t1 << "is 80% ";
            }
        }
        if (r1 > 205 && ((r - s.o) <= 0 && (r - s.o) > -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 97% ";
                cout << "Winning percentage of team " << x.t1 << "is 3% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 87% ";
                cout << "Winning percentage of team " << x.t1 << "is 13% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is 99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 85% ";
                cout << "Winning percentage of team " << x.t1 << "is 15% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 90% ";
                cout << "Winning percentage of team " << x.t1 << "is 10% ";
            }
        }
        else if (r1 > 205 && ((r - s.o) >= 0 && (r - s.o) < 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 95% ";
                cout << "Winning percentage of team " << x.t1 << "is 5% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 92% ";
                cout << "Winning percentage of team " << x.t1 << "is 8% ";
            }
            else if ((wr - y.ball) == 0)
            {
                cout << "Winning percentage of team " << x.t << "is 88% ";
                cout << "Winning percentage of team " << x.t1 << "is 12% ";
            }
        }
        else if ((r1 <= 205 && r1 > 185) && ((r - s.o) <= 0 && (r - s.o) > -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 93% ";
                cout << "Winning percentage of team " << x.t1 << "is 7% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 85% ";
                cout << "Winning percentage of team " << x.t1 << "is 15% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  88% ";
                cout << "Winning percentage of team " << x.t1 << "is 12% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 78% ";
                cout << "Winning percentage of team " << x.t1 << "is 22% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 <= 205 && r1 > 185) && ((r - s.o) >= 0 && (r - s.o) < 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 88% ";
                cout << "Winning percentage of team " << x.t1 << "is 12% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  99% ";
                cout << "Winning percentage of team " << x.t1 << "is 1% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 87% ";
                cout << "Winning percentage of team " << x.t1 << "is 13% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 <= 185 && r1 >= 169) && ((r - s.o) <= 0 && (r - s.o) > -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 75% ";
                cout << "Winning percentage of team " << x.t1 << "is 25% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 60% ";
                cout << "Winning percentage of team " << x.t1 << "is 40% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is 70% ";
                cout << "Winning percentage of team " << x.t1 << "is 30% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 43% ";
                cout << "Winning percentage of team " << x.t1 << "is 57% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 <= 185 && r1 >= 169) && ((r - s.o) >= 0 && (r - s.o) < 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 79% ";
                cout << "Winning percentage of team " << x.t1 << "is 21% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 64% ";
                cout << "Winning percentage of team " << x.t1 << "is 36% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is 80% ";
                cout << "Winning percentage of team " << x.t1 << "is 20% ";
            }
            else if ((wr - y.ball) > 2)
            {
                m.halfpredict(s,x);
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 <= 168 && r1 >= 150) && ((r - s.o) <= 0 && (r - s.o) > -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 45% ";
                cout << "Winning percentage of team " << x.t1 << "is 55% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 40% ";
                cout << "Winning percentage of team " << x.t1 << "is 60% ";
            }
            else if ((wr - y.ball) < -2)
            {
                m.halfpredict(s,x);
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is  30% ";
                cout << "Winning percentage of team " << x.t1 << "is 70% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 < 149) && ((r - s.o) >= 0 && (r - s.o) < 11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 40% ";
                cout << "Winning percentage of team " << x.t1 << "is 60% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 31% ";
                cout << "Winning percentage of team " << x.t1 << "is 69% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  45% ";
                cout << "Winning percentage of team " << x.t1 << "is 55% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 25% ";
                cout << "Winning percentage of team " << x.t1 << "is 75% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
        else if ((r1 < 149) && ((r - s.o) <= 0 && (r - s.o) > -11))
        {
            if ((wr - y.ball) <= -1 && (wr - y.ball) >= -2)
            {
                cout << "Winning percentage of team " << x.t << "is 43% ";
                cout << "Winning percentage of team " << x.t1 << "is 58% ";
            }
            else if ((wr - y.ball) >= 1 && (wr - y.ball) <= 2)
            {
                cout << "Winning percentage of team " << x.t << "is 30% ";
                cout << "Winning percentage of team " << x.t1 << "is 70% ";
            }
            else if ((wr - y.ball) < -2)
            {
                cout << "Winning percentage of team " << x.t << "is  42% ";
                cout << "Winning percentage of team " << x.t1 << "is 58% ";
            }
            else if ((wr - y.ball) > 2)
            {
                cout << "Winning percentage of team " << x.t << "is 10% ";
                cout << "Winning percentage of team " << x.t1 << "is 90% ";
            }
            else if ((wr - y.ball) == 0)
            {
                m.halfpredict(s,x);
            }
        }
    }
int main()
{
    char t;
    player d;
    teamhistroy b;
    over y;
    prediction c;
    wicketprediction e;
    winprediction f;
    team j;
    half h;
    d.wickets();
    b.condition();
    c.predicts(d,b,y);
    e.wicketpredicts(d,y);
    cout<<"2nd team is batting ??";
    cout<<"Enter 'Y' or 'y' if yes and 'N' or 'n' for no "<<endl;
    cin>>t;
    if(t=='Y'  || t=='y')
    f.winpredicts(j,y,d,h);
    return 0;
}