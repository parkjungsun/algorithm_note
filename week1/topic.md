# 문제
2309, 10808, 2979, 10988, 1159, 11655, 9996, 
2559, 1620, 9375, 1213, 1940, 3986, 1629, 4375

# 라이브러리
- bits/stdc++.h
- iostream, stdio.h, string.h, algorithm,

# 입출력 싱크
ios_base::sync_with_stdio(false); 
cin.tie(NULL);
cout.tie(NULL);
- 입출력싱크를 맞추는 것을 해제한다. 
- cin, cout은 c라이브러리인 stdio 버퍼와 동기화하느라 시간을 소비한다.

# STL
- 알고리즘
    - 정렬, 탐색 함수 sort() 등

- 컨테이너 
    - 시퀀스 컨테이너
        array, vector, deque, forword_list, list
    - 연관 컨테이너 (자동 정렬됨)
        set, map, multiset, multimap /* multi : 중복 가능한 것*/
    - 정렬되지 않은 연관 컨테이너
        unordered_set, unordered_map, unordered_multiset, unordered_multimap
    - 컨테이너 어댑터 (시퀀스 컨테이너 이용해 만든 자료구조)
        (stack, queue -> deque), (priority_queue -> vector)

- 이터레이터
    - 컨테이너에 저장되어 있는 요소의 주소를 가리키는 개체를 말하며 포인터를    일반화 한 것이다. vector, map 등에서 이터레이터를 통해 쉽게 순회
    - &* 를 통해 해당 요소의 주소값 반환
    - vector<int>::iterator 
    - v.begin() - 시작위치, v.end() - 끝 위치, 
    - advacne(iterator, cnt) - 이터레이터 cnt 만큼 증가
    - fill(ForwardIterator first,ForwardIterator last, const T& val);

# 입력, 출력
- cin : 개행문자(띄어쓰기, 엔터)까지 입력받음
- scanf : 형식을 지정해서 받음
- getline(cin, string)

- cout : 소숫점 자리수 출력시 cout.precision(자릿수)
- printf : string type 출력시 .c_str() 사용해야함
    while(cin >> n) {
        
    }

# 문자 char, 문자열 string
- char 1 byte /* 영어 1 byte, 한글 3 byte */
- string
    - pop_back() : 맨뒤 하나 제거, push_back() : 맨뒤 하나 추가
    - size() :  
    - begin(), end() : 마지막 요소 다음 - 이터레이터 반환
    - insert(offset, char) : 특정 위치 문자열 삽입 O(n)
    - erase(위치, 크기) : 특정 위치에 크기만큼 문자열 지움 O(n)
    - find(char) : 위치 찾고 없을 때, string::npos 반환
    - substr(위치, 크기)
    - reverse(첫 이터레이터, 마지막 이터레이터)
    - atoi(s.c_str()) -> 문자열이면 0 반환, 숫자면 숫자반환

# split() 구현하기 : c++에서는 지원하지 않는다.
vector<string> split(string input, string delimiter) {
    vector<string> ret;
    long long pos = 0;
    string token = "";
    while((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos)
        ret.push_back(token);
        input.erase(0, pos + delimiter.lenght());
    }
    ret.push_back(input);
    return ret;
}

# 자료형 
int 4 byte
const int INF = 987654321; 
const int INF2 = 1e9; // 2,147,483,647 (20억)

long long 8 byte
typedef long long ll;
ll INF = 1e18; // 9,223,372,036,854,775,807 (30억)

double 8byte, float 4byte

unsigned long long 8 byte

pair<int, int> pi;
- make_pair(a, b) // {a, b}
- a = pi.first, b =pi.second
- tie(a, b) = pi; 

tuple<int, int, int> tl;
- make_tuple(a,b,c) // {a,b,c}
- a = get<0>(tl), b = get<1>(tl), c = get<2>(tl)
- tie(a, b, c) = tl;

# 기초 함수

memset(배열, 값, 배열의 크기)

memcpy(dest, source, size);

sort(first, last, *커스텀 비교함수) -> O(nlogn)
// less<int>(), greater<int>()
// bool cmp(pair<int, int> a, pair<int, int> b) {
//    return a.first > b.first;
// }

unique(v.begin(), v.end())
- 중복되지 않은 요소로 채우고, 그 다음 이터레이터 반환한다.

erase(unique(v.begin(), v.end()), v.end());

lower_bound(v.begin(), v.end(), x)
> 정렬된 배열에서 어떤 값 나오기 시작하는 지점

upper_bound(v.begin(), v.end(), x)
> 정렬된 배열에서 어떤 값 나오는 마지막 다음 지점

pow(), sqrt()

# vector<int> : 연속된 메모리 공간에 데이터 저장
- size() 들어가있는 개수, capacity() 총 용량
- pop_back(), push_back()
- erase(iterator from, iterator to)
- find(from, to, value)
- clear()
- fill(from, to, value)

# list<int> : 연속되지 않는 메모리 공간에 데이터 저장
- 싱글연결리스트, 이중연결리스트, 원형연결리스트
- push_front(v), push_back(v), insert(idx, value)
- pop_front(), pop_back() erase(idx)
- front(), back(), clear()

* vector와 array는 랜덤접근가능
* list, stack, queue는 순차 접근 가능

# map<string, string> : key - value 쌍으로 이루어져있는 정렬된 연관 컨테이너
- "레드 - 블랙트리"로 구현 O(logN)
- insert({key : value}), size(), erase(key), find(key), clear()
- 참조시 바로 int 면 0 할당, string 이면 빈값 참조됨.

이렇게 참조
if(mp.find(1) == mp.end()) {
    mp[1] = 2;
}


# unordered_map vs map
- map : 정렬됨 / 레드블랙트리기반 / 탐색, 삽입, 삭제 O(logN)
- unordered_map : 정렬 안됨 / 해시테이블 기반 / O(1) ~ O(N)

# set<?> vs multiset<?>

# stack<?>
- 삽입, 삭제 O(1) / 탐색 O(n)
- push(v), pop(), top(), size()

# queue<?>
- 삽입, 삭제 O(1) / 탐색 O(n)
- push(v), pop(), size(), front()

# deque<?>
- 앞뒤로 삽입, 삭제, 참조가 가능
- push_back(), push_front(), front(), back(), size(), pop_front(), pop_back()

# 구조체
struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x)
    Point() {y = -1; x = -1;}
    bool operator < (const Point & a) const {
        if(x == a.x) return y < a.y;
        return x < a.x;
    }
}

# priority queue<자료형, 컨테이너, 비교함수>
- 요소에 어떠한 우선순위가 추가로 부여되어 있는 컨테이너
- 힙은 완전이진트리 / 최대힙은 루트에 최대값, 최소힙은 루트에 최소값
- ex) priority_queue<int, vector<int>, greater<int>> // 오름차순
- ex) priority_queue<int, vector<int>, less<int>> // 내림차순
- ex) priority_queue<Point> - 우선순위 큐에 커스텀정렬을 넣을 때 반대로 해야함
- ex) priority_queue<Point, vector<Point>, cmp>

# 순열
- 아래 함수를 사용할 때는, 알맞은 정렬을 한 후에 써야 순열이 나온다.
- next_permutation : 오름차순 배열 기반으로 순열 만듬
    void printV(vector<int> &v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
    do {
        printV(v);
    } while (next_permutation(v.begin(), v.end()))
- prev_permutation : 내림차순 배열 기반으로 순열 만듬
    do {
        printV(v);
    } while (prev_permutation(v.begin(), v.end()))
- 재귀를 이용한 순열 
    void makePermutation(int n, int r, int depth) {
        if(r == depth) {
            printV(v);
            return;
        }
        for(int i = depth; i< n; i++) {
            swap(v[i], v[depth]);
            makePermutation(n, r, depth + 1);
            swap(v[i], v[depth]);
        }
        return 0;
    }

# 조합
- 재귀를 이용한 조합
    void combi(int start, vector<int> b) {
        if(b.size() == k) {
            print(b);
            return;
        }
        for(int i = start + 1; i < n; i++) {
            b.push_back(i);
            combi(i, b);
            b.pop_back();
        }
        return;
    }

# 정수론
- 최대공약수 gcd
    int gcd(int a, int b) /* a < b */ {
        if ( a == 0 ) return b;
        return gcd( b % a, a);
    }
- 최소공배수 lcm
    int lcm(int a, int b) {
        return (a * b) / gcd(a * b);
    }

# 에라토스테네스의 체
- 소수가 아닌 값들에 대한 불리언 배열을 만들어 소수만을 걸러낼 수 있는 방법

- 소수 판별
bool check(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i =2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

# 시계방향과 반시계방향 회전, rotate(first, middle, last)
- middle이 first로 가면서 회전하는 것
- rotate(v.begin(), v.begin() + 1, v.end());
- rotate(v.begin(), v.begin() + v.size() - 1, v.end());

# 배열의 합 accumulate()
- accumulate(v.begin(), v.end(), 0);

# 배열의 최댓값 max_element()
- *max_element(v.begin(), v.end());

# 배열 90도 회전
<pre>
<code>
void rotate90(vector<vector<int>> &key) {
    int m = key.size();
    /* m * m 크기 배열 */
    vector<vector<int>> temp(m, vector<int>(m, 0));

    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) {
            temp[i][j] = key[j][m - i - 1];
        }
    }
}
</code>
</pre>
