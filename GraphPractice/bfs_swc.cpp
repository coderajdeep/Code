#include<iostream>
using namespace std;
#define size 200
#define INT_MIN -2147483648
#define R 30
#define C 30

struct point {
	int x,y;
};

int front, rear;
point arr[size];
char tb[R][C];
bool visited[R][C];
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void init(int r, int c) {
	for(int i=0; i<r; ++i) {
		for(int j=0; j<c; ++j) {
			tb[i][j] = '0'; // 0 means wall
			visited[i][j] = false;
		}
	}
}

bool isEmpty() {
	return (front==-1);
}

bool isFull() {
	return (front==0 && rear==(size-1)) || (rear==front-1);
}

int getSize() {
	if(isEmpty()) return 0;
	if(isFull()) return size-1;
	if(front<=rear) return (rear-front+1);
	else return (rear+1)+(size-front);
}

point Front() {
	if(isEmpty()) return {INT_MIN, INT_MIN};
	return arr[front];
}

void push(point value) {
	// check when array is full
	if(isFull()) return;
	// check when array empty
	if(isEmpty()) {
		rear = 0;
		front = 0;
	}
	// when rear == size-1 and front!=0
	// if rear == size-1 and front==0
	// then array is full
	else if(rear==size-1) {
		rear = 0;
	}
	else {
		++rear;
	}
	arr[rear] = value;
}

void pop() {
	if(isEmpty()) return;
	else if(rear==front) {
		rear = -1;
		front = -1;
	}
	else if(front==size-1) {
		front = 0;
	}
	else {
		++front;
	}
}

int bfs(int r, int c) {
	visited[0][0] = true;
	push({0, 0});
	int ans = 0;

	// cout<<"BFS Started : ";

	while(!isEmpty()) {
		int t = getSize();
		++ans;
		while(t--) {
			point u = Front();
			// cout<<"("<<u.x<<" "<<u.y<<") ";
			pop();
			for(int i=0; i<4; ++i) {
				int a = u.x + dirs[i][0];
				int b = u.y + dirs[i][1];

				if(a>=0 && a<r && b>=0 && b<c && tb[a][b]=='1' && !visited[a][b]) {
					visited[a][b] = true;
					push({a, b});
					if(a==r-1 && b==c-1) return ans;
				}
			}
		}
	}
	// cout<<"BFS ended\n";
	return INT_MIN;
}

int main() {
	int T;
	cin>>T;

	for(int t=1; t<=T; ++t) {
		int r, c;
		cin>>r>>c;
		for(int i=0; i<r; ++i) {
			for(int j=0; j<c; ++j) {
				cin>>tb[i][j];
			}
		}
		cout<<"#"<<t<<" "<<bfs(r, c)<<endl;
	}
	return 0;
}