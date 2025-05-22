#include <iostream>
#include <iomanip>

using namespace std;

class Grade {
private:
    char letter;
    float score;

    void calcGrade() {
        if (score >= 90) {
            letter = 'A';
        } else if (score >= 80) {
            letter = 'B';
        } else if (score >= 70) {
            letter = 'C';
        } else if (score >= 60) {
            letter = 'D';
        } else {
            letter = 'F';
        }
    }

public:
    void setScore(float s) {
        score = s;
        calcGrade();
    }

    float getScore() const {
        return score;
    }

    char getLetter() const {
        return letter;
    }
};

class Test : public Grade {
private:
    int numQuestions;
    float pointsEach;
    int numMissed;

public:
    Test(int total, int missed) : numQuestions(total), numMissed(missed) {
        pointsEach = 100.0f / numQuestions;
        int correct = numQuestions - numMissed;
        float score = correct * pointsEach;
        setScore(score);
    }
};

int main() {
    int total, missed;
    cin >> total >> missed;

    Test test(total, missed);

    cout << fixed << setprecision(2);
    cout << "The score is:" << test.getScore() << endl;
    cout << "The grade is:" << test.getLetter() << endl;

    return 0;
}