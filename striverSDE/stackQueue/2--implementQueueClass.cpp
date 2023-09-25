// Implement queue class -- coding ninjas

class Queue {

	int front, rear;
	vector<int> arr;

public:
	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		arr[this->rear] = e;
		this->rear += 1;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		if(this->isEmpty()) {
			return -1;
		}
		int frontElement = arr[this->front];
		this->front += 1;
		return frontElement;
	}

	bool isEmpty() {
		return (this->front == this->rear);
	}
};