#include <iostream>
#include <string>

using namespace std;

class Ball {
protected:
    string opponent;
public:
    Ball(const string& opp) : opponent(opp) {}
    virtual void display() = 0;
    virtual ~Ball() {}
};

class Basketball : public Ball {
private:
    int self_score;
    int opp_score;
public:
    Basketball(const string& opp, const string& score) : Ball(opp) {
        size_t pos = score.find(':');
        self_score = stoi(score.substr(0, pos));
        opp_score = stoi(score.substr(pos + 1));
    }
    void display() override {
        int points = (self_score > opp_score) ? 2 : 1;
        cout << opponent << " " << points << endl;
    }
};

class Football : public Ball {
private:
    int self_score;
    int opp_score;
public:
    Football(const string& opp, const string& score) : Ball(opp) {
        size_t pos = score.find(':');
        self_score = stoi(score.substr(0, pos));
        opp_score = stoi(score.substr(pos + 1));
    }
    void display() override {
        int points = 0;
        if (self_score > opp_score) {
            points = 3;
        } else if (self_score == opp_score) {
            points = 1;
        }
        cout << opponent << " " << points << endl;
    }
};

class Volleyball : public Ball {
private:
    int self_sets;
    int opp_sets;
public:
    Volleyball(const string& opp, const string& score) : Ball(opp) {
        size_t pos = score.find(':');
        self_sets = stoi(score.substr(0, pos));
        opp_sets = stoi(score.substr(pos + 1));
    }
    void display() override {
        int points = 0;
        if (self_sets > opp_sets) {
            if ((self_sets == 3 && opp_sets == 0) || (self_sets == 3 && opp_sets == 1)) {
                points = 3;
            } else if (self_sets == 3 && opp_sets == 2) {
                points = 2;
            }
        } else {
            if (self_sets == 2 && opp_sets == 3) {
                points = 1;
            }
        }
        cout << opponent << " " << points << endl;
    }
};

int main() {
    Ball* pb[20];
    int count = 0;
    int type;
    while (cin >> type && type != 0) {
        string opponent, score;
        cin >> opponent >> score;
        switch (type) {
            case 1:
                pb[count] = new Basketball(opponent, score);
                break;
            case 2:
                pb[count] = new Football(opponent, score);
                break;
            case 3:
                pb[count] = new Volleyball(opponent, score);
                break;
            default:
                continue;
        }
        count++;
    }
    for (int i = 0; i < count; ++i) {
        pb[i]->display();
        delete pb[i];
    }
    return 0;
}