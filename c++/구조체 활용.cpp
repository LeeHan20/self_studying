#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <deque>
#include <time.h>
#include <iomanip>
using namespace std;

//큐에 들어갈 구조체
//true면 target, false면 그냥 element
struct queue_elements {
    int priority;
    bool istarget;
    
    queue_elements(int p, bool i) : priority(p), istarget(i) {}
};

int main() {
    int test_case;
    cin >> test_case;
    
    //loop
    for (int t = 0; t < test_case; ++t) {
        int printing_number;
        int picking_number;
        cin >> printing_number >> picking_number;
        
        //max값이 필요하여 vector와 queue를 동시에 사용
        vector<int> papers(printing_number);
        queue<queue_elements> q;
        
        //target과 element를 구별하여 queue에 저장하고 vector는 일괄적으로 저장함
        for (int i = 0; i < printing_number; ++i) {
            int input;
            cin >> input;
            papers[i] = input;
            if (i == picking_number) {
                q.emplace(input, true);
            }
            else {
                q.emplace(input, false);
            }
        }
        
        //문제해결 루프 시작
        // 1. vector에서 max값을 꺼냄
        // 2-1. queue의 front의 prority가 max_value와 같다면 pop하고 cnt를 1 올리고 백터에서 해당 요소를 제거함
        // pop 되었다면 max_value를 초기화함
        // 2-2. 다르다면 front의 정보를 저장하고 emplace한 후 pop함
        // 3. 만약 pop이 된 요소가 istarget이라면 while루프를 종료하고 cnt를 출력함
        int number_out_cnt = 1;
        int max_value = *max_element(papers.begin(), papers.end());
        while (true) {
            
            if (q.front().priority != max_value) {
                q.emplace(q.front());
                q.pop();
            }
            else {
                if (q.front().istarget) {
                    cout << number_out_cnt << "\n";
                    break;
                }
                papers.erase(remove(papers.begin(), papers.end(), max_value), papers.end());
                number_out_cnt++;
                max_value = *max_element(papers.begin(), papers.end());
            }
        }
    }
    
    return 0;
}

//1966번

//unsolved prov
//
//4 6 5 6 7
//4 6 5 6 7

//6 5 6 7 4
//5 6 7 4 6
//6 7 4 6 5
//7 4 6 5 6
//4 6 5 6
//6 5 6 4
//5 6 4
//6 4 5
//4 5
//5 4
//4

//구조체를 써서 큐에 사용자 정의 클래스를 넣고 bool, int를 넣어서 true인 요소가 나오면 그 때 카운트를 종료하는 것?

//priority_queue를 쓰면 쉬울 것 같다
