#include <iostream>
#include <cstdlib>
#include <ctime>

#define x 0
#define y 1
#define z 2
#define N 100

using namespace std;

void games(int *a, int *b, int *r);
int whoWins(int *a, int *b, int *r);
void printGAME(int *a, int *b, int *r, int winner);

//ROCK(x) = 0, PAPER(y) = 1, SCISSORS(z) = 2
int main ()
{
    int *A = (int *) malloc (N * sizeof(int));//Player 1
    int *B = (int *) malloc (N * sizeof(int));//Player 2
    int *R = (int *) malloc (N * sizeof(int));//DRAW
    int winner = 0;
    games(A, B, R);
    winner = whoWins(A, B, R);
    printGAME(A, B, R, winner);
    free(A);
    free(B);
    free(R);
    return 0;
}

void games(int *a, int *b, int *r)
{
    int i = x;
    time_t t;
    srand((unsigned) time(&t));
    for(i = x ; i < N ; i++)
    {
        a[i] = rand() % 3;
        b[i] = rand() % 3;
        if(a[i] == b[i])
        {
            r[i] = x; //DRAW
        }else if((a[i] == z && b[i] == y) || (a[i] == y && b[i] == x) || (a[i] == x && b[i] == z))
        {
            r[i] = y; //A WIN
        }else
        {
            r[i] = z; //B WIN
        }
    }
}

int whoWins(int *a, int *b, int *r)
{
    int i = x;
    int m = x;
    int n = x;
    for(i = x ; i < N ; i++)
    {
        if(r[i] == z)
        {
            m++;
        }else if(r[i] == y)
        {
            n++;
        }
    }
    if(n == m)
    {
        return x;
    }else if(n > m)
    {
        return y;
    }else
    {
        return z;
    }
}

void printGAME(int *a, int *b, int *r, int winner)
{
    int i = x;
    for(i = x ; i < N ; i++)
    {
        if(a[i] == x)
        {
            //printf("ROCK     ");
            cout << "ROCK     ";
        }else if(a[i] == y)
        {
            //printf("PAPER    ");
            cout << "PAPER    ";
        }else
        {
            //printf("SCISSORS ");
            cout << "SCISSORS ";
        }
        //printf("vs");
        cout << "vs";
        if(b[i] == x)
        {
            //printf("     ROCK");
            cout << "     ROCK";
        }else if(b[i] == y)
        {
            //printf("    PAPER");
            cout << "    PAPER";
        }else
        {
            //printf(" SCISSORS");
            cout << " SCISSORS";
        }
        //printf(" WINS:");
        cout << " WINS:";
        if(r[i] == x)
        {
            //printf(" DRAW\n");
            cout << " DRAW\n";
        }else if(r[i] == y)
        {
            //printf(" P1\n");
            cout << " P1\n";
        }else
        {
            //printf(" P2\n");
            cout << " P2\n";
        }
    }
    if(winner == x)
    {
        //printf("->WNNIER: DRAW<-\n");
        cout << "->WNNIER: DRAW<-\n";
    }else if(winner == y)
    {
        //printf("->WINNER: P1<-\n");
        cout << "->WNNIER: P1<-\n";
    }else
    {
        //printf("->WINNER: P2<-\n");
        cout << "->WNNIER: P2<-\n";
    }
}
