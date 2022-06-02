#include<iostream>
using namespace std;
#define size 10

int arr[size];
int front, rear;

bool isEmpty() {
	return (front==-1);
}

bool isFull() {
	// this need to check
	return ((front==0 && rear==(size-1)) || (rear==front-1));
}

int main() {

}