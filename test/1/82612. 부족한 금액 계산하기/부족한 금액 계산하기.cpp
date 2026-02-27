using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long totalPrice = (long long)price*(((long long)count*(count+1))/2);
    if(money - totalPrice >= 0) return 0;
    answer = money - totalPrice;
    return -answer;
}