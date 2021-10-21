// C++14 implementation of the
// above approach
#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a,vector<int> b)
{

	if(a[0] != b[0])
		return a[0] < b[0];
		
	return a[1] - b[1];
}

// Function to find time slot of
// maximum concurrent meeting
void maxConcurrentMeetingSlot(
	vector<vector<int>> meetings)
{
	
	// Sort array by
	// start time of meeting
	sort(meetings.begin(), meetings.end(), cmp);

	// Declare Minheap
	priority_queue<int, vector<int>,
					greater<int>> pq;
	
	// Insert first meeting end time
	pq.push(meetings[0][1]);

	// Initialize max_len,
	// max_start and max_end
	int max_len = 0, max_start = 0;
	int max_end = 0;

	// Traverse over sorted array
	// to find required slot
	for(auto k : meetings)
	{
		
		// Pop all meetings that end
		// before current meeting
		while (pq.size() > 0 &&
					k[0] >= pq.top())
			pq.pop();

		// Push current meeting end time
		pq.push(k[1]);

		// Update max_len, max_start
		// and max_end if size of
		// queue is greater than max_len
		if (pq.size() > max_len)
		{
			max_len = pq.size();
			max_start = k[0];
			max_end = pq.top();
		}
	}

	// Print slot of maximum
	// concurrent meeting
	cout << max_start << " " << max_end;
}

// Driver Code
int main()
{
	
	// Given array of meetings
	vector<vector<int>> meetings = { { 100, 200 },
									{ 50, 300 },
									{ 300, 400 } };
									
	// Function call
	maxConcurrentMeetingSlot(meetings);
}

// This code is contributed by mohit kumar 29
