#include <queue>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    priority_queue<pair<int, string>> pq ;

    pq.emplace( 45, "abc" ) ;
    pq.emplace( 78, "abc" ) ;
    pq.emplace( 12, "xyz" ) ;
    pq.emplace( 25, "pqr" ) ;
    pq.emplace( 45, "def" ) ;

    while( !pq.empty() )
    {
        pair<int,string> p = pq.top() ;
        cout << p.first << ',' << p.second << endl;
        pq.pop() ;
    }
}
