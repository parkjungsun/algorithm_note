### 2주차 그래프이론, DFS, BFS

# 20 문제
- 23(월) 2178 o, 1012 o, 2468 o
- 24(화) 2583 o, 1992, 2828
- 28(토) 2910 o, 4659 o, 2870 o, 10709
- 29(일) 3474, 2852, 1436 o
- 30(월) 9012 o, 4949 o, 14502
- 31(화) 2636, 1068, 1325, 17298

# Remind
- 1992, 2828, 10709, 3474, 2852, 14502, 2636, 1068, 1325, 17298

# 그래프이론의 기초(Graph, Vertex, Edge, Weight)
- 정점, 노드 (vertex) : 그래프 형성 기본 단위
- 간선 (edge) : 단방향, 양방향
- degree : indegree(들어오는 간선), outdegree(나가는 간선)
- 가중치 (weight)

# 트리(Tree Data Structure)
- 자식노드와 부모노드로 이루어진 무방향 그래프(사이클 x)
- 루트노드 - 내부노드 - 리프노드
- v - 1 = e
- 깊이 (depth), 높이 (height)

# 이진트리(BT)와 이진탐색트리(BST)
- 이진트리 : 자식노드 수가 2개 이하인 트리
  - 정 이진트리 : 자식 노드가 0 or 2
  - 완전 이진트리 : 왼쪽부터 순서대로 채워진 트리
  - 변질 이진트리 : 자식 노드가 하나밖에 없는 이진트리
  - 포화 이진트리 : 모든 노드가 꽉 차있는 트리
  - 균형 이진트리 : 모든 노드의 왼쪽 하위트리와 오른쪽 하위트리 차이가 1 이하인 트리(레드블랙트리 - map, set)
- 이진탐색트리 : 왼쪽노드에는 작은값, 오른쪽 노드에는 큰값이 있음

### 컴퓨터에게 그래프에 대해 알려줄 방법 : 인접행렬, 인접리스트
# 인접행렬(adjacency matrix)
- 정점과 간선의 관계를 나타내는 bool 타입의 정사각형 행렬
- 공간복잡도 : O(V^2)
- 시간복잡도 : O(1) ~ O(V^2)

# 인접리스트(adjacency list)
- 정점과 간선의 관계를 나타내는 연결리스트
- 공간복잡도 : O(V+E)
- 시간복잡도 : O(V) ~ O(V+E)

# 인접행렬과 인접리스트의 차이
- 그래프가 희소할때 (sparse) : 인접리스트
- 그래프가 조밀할때 (dense) : 인접행렬

# 맵과 방향벡터(direction vector)
- 미로 문제는 인접행렬 문제가 아니다.
- 4방향으로 탐색해나아가는 문제일 경우가 높다.
- 방향벡터는 dy, dx로 정의 됨.
  - dy[] = {-1, 0, 1, 0}
  - dx[] = {0, 1, 0, -1}

# 연결된 컴포넌트(connected component)
- 연결된 하위그래프, 연결된 하나의 덩어리

# 깊이우선탐색(DFS)
- 인접한 노드들을 재귀적으로 방문
```
DFS(u, adj)
    u.visited = true
    for each v ∈ adj[u]
        if v.visited == false
            DFS(v, adj)
```

# 너비우선탐색(BFS)
- 현재 깊이의 모든 정점을 탐색하며 방문

### 방문처리
```
BFS(G, u)
    u.visited = true
    q.push(u);
    while(q.size()) 
        u = q.front() 
        q.pop()
        for each v ∈ G.Adj[u]
            if v.visited == false
                v.visited = true
                q.push(v) 
```

### 가중치가 같은 그래프 내에서 최단거리
```
BFS(G, u)
    u.visited = 1
    q.push(u);
    while(q.size()) 
        u = q.front() 
        q.pop()
        for each v ∈ G.Adj[u]
            if v.visited == false
                v.visited = u.visited + 1 // 거리 구하는
                q.push(v) 
```
# 트리순회
- 후위순회 post (DFS)
  - Bottom -> Top, Left -> Right 
```
postorder( node )
    if (node.visited == false) 
        postorder( node->left ) 
        postorder( node->right )
        node.visited = true
```
- 전위순회 pre (DFS)
  - Top -> Bottom, Left -> Right
```
preorder( node )
    if (node.visited == false)
        node.visited = true
        preorder( node->left )
        preorder( node->right )
```
- 중위순회 in (DFS)
  - Left -> Node -> Right
```
inorder( node )
    if (node.visited == false) 
        inorder( node->left )
        node.visited = true
        inorder( node->right )
```
- 레벨순회 (BFS)
  - LEFT -> Right, Top -> Bottom