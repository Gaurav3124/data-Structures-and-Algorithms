#include<bits/stdc++.h>
using namespace std;

//Very important : Base case

//TRUST the function (it's like mathematical induction)

// print "Hello" n times
void say_hello(int n) {
	if (n == 0) return; // Base case or stoping case
	cout << "Hello " << n << endl ;
	say_hello(n - 1);
}
/*this will print:
hello n
hello n-1
.
.
.
hello 1
*/

void say_hello(int n) {
	if (n == 0) return; // Base case or stoping case
	say_hello(n - 1);
	cout << "Hello " << n << endl ;
}
/*this will print from
hello 1
.
.
.
hello n-1 // we can see it as say_hello(n-1) till here, so we have to trust the process
hello n
*/



// same for sum till n digits
/* sum :[ 1+ 2+ 3+ 4 . . . + (n-1) ]+ n
								^
				till here it can be considered sum till (n-1)
*/
int sum_n(int n) {
	if (n == 0) return 0;
	return sum_n(n - 1) + n;
}

//sum of digits of a number
/*
no = 163528;
sum_no = (1 + 6 + 3 + 5 + 2) + 8;
						^
				sum of digits of no 16352 (this will be green box)
*/
int sum_of_digits(int n) {
	if (n <= 10) return n % 10;
	return sum_of_digits(n / 10) + n % 10;
}

// pattern_printing
/*
[1
1 2
1 2 3
.
.
1 2 3 . . . n-1 ] <- till here will be the green box
1 2 3 . . . n-1 n
*/
void pattern_printing(int n) {
	if (n == 0 ) return;
	pattern_printing(n - 1);// trust
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	cout << endl;
}

// pattern printing 2
/*
1 2 3 . . . n
[1 2 3
1 2
1
1 2
1 2 3]<- green box
1 2 3 . . . n
*/
void pattern_printing(int n) {
	if (n == 1) {
		cout << "1" << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	cout << endl;

	pattern_printing(n - 1);// trust the function

	for (int i = 1; i <= n; i++) {
		cout << i << " ";
	}
	cout << endl;
}

// fibonacci digit of n-th index
/*
digits : 0,1,1,2,3,5,8,13,21,34,....
index :  1 2 3 4 5 6 7 8  9  10 ....

f(n) = f(n-1) + f(n-2)
*/
// trust to return the n-th index digit
int fib(int n) {
	if (n == 1) return 0;
	if (n == 2) return 1;
	return fib(n - 1) + fib(n - 2);
}

// VERY IMPORTANT : always find green box

int main() {

	say_hello(10);

	return 0;
}


//Tower of Hanoi
/*
	|       |       |
	|		|		|
	|		|		|
	|		|		|
    s       h       d
  */


int solve(int n, int s, int d, int h, int &count) {
	if (n == 1) {
		cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
		count++;
		return count;
	}
	solve(n - 1, s, h, d, count);
	cout << "move disk " << n << " from rod " << s << " to rod" << d << endl  ;
	count++;
	solve(n - 1, h, d, s, count);
	return count;
}
long long toh(int N, int from, int to, int aux) {
	int count = 0;
	int n = N;
	int s = from;
	int d = to;
	int h = aux;
	long long int ans = solve(n, s, d, h, count);
	return ans;
}
//end

// print all subset/powerset/all subsequence (IP-OP method)(recursive tree)

/*
powerset = all subset of a given set
subsequence = order of elements should be mentained in sequence
substring should be continuous
everything is allowed in subset
representing in venn diagram, 3 concurrent circles are formed with
innermost being substring -> subsequence -> subset
*/

void subsets(string ip, string op) {
	if (ip.length() == 0) {			//base condition
		cout << op << " ";
		return;
	}
	string op1 = op;
	string op2 = op;  // initialisation for the 2 branches in recursion tree
	op2.push_back(ip[0]); // in op1 we take decision in which we do not take the input index and vica versa in op2
	ip.erase(ip.begin() + 0); // ip gets smaller
	subsets(ip, op1);
	subsets(ip, op2);
}

int main() {
	string ip;
	cin >> ip;
	string op = "";//empty string
	subsets(ip, op);
}

// permutation with spaces(corner spaces not allowed)

/*
input string: "ABC"
output permutations: "A BC" "AB C" "ABC" "A B C"
*/

void solve(string ip, string op) {
	if (ip.length() == 0) {
		cout << op << " ";
		return;
	}
	string op1 = op; //pushback without space
	string op2 = op; //pushback with space
	op1.push_back(ip[0]);
	op2.push_back(" ");
	op2.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	solve(ip, op1);
	solve(ip, op2);
	return;
}

int main() {
	string ip;
	cin >> ip;
	string op = "";
	op.push_back(ip[0]);
	ip.erase(ip.begin() + 0);
	solve(ip, op);
}

//Generate all balanced paranthesis

void solve(int &open, int &close, string op, vector<string> &v) {
	if (open == 0 && close == 0) { //base case
		v.push_back(op);
		return;
	}
	if (open != 0) { //this branch will always be available
		string op1 = op;
		op1.push_back("(");
		open--;
		solve(open, close, op1, v);
	}
	if (close > open) { // we get the option to use closed parenthesis when number of close > number of open parenthesis
		string op2 = op;
		op2.push_back(")");
		close--;
		solve(open, close, op2, v);
	}
	return;
}

vector<string> func(int n) {
	vector<string> v;
	int close = n, open = n;
	string op = "";
	solve(open, close, op, v);
	return v;
}

//Josephus problem
/*
IBH method

*/

int solve(vector<int> &v, int k, int index) { // k here will be k-1 as index is set back one unit after deletion
	if (v.size == 0) return v[0];
	index = (index + k) % v.size();
	v.erase(v.begin() + index);
	solve(v, k, index);
}

int main() {
	vector<int> v;
	int n, k;
	cin >> n >> k;
	f(i, 5) {
		v.push_back(i++);
	}
	ans = solve(v, k--, 0);// initial index will be 0
	return ans;
}

------------------------------------------------------------------------------------------------------
//DYNAMIC PROGRAMMING
/*
recursion mei 2 functions call ho rahe ho toh DP.
*/

///////////////// 0-1 knapsack with memoization/////////////////////

int t[n][W]; //global variable
memset(t, -1, sizeof(t)); //initializing all matrix value by -1

int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	if (t[n][W] != -1) return t[n][W];

	// If weight of the nth item is more
	// than Knapsack capacity W, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > W)
		return t[n][W] = knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return t[n][W] = max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
		                     knapSack(W, wt, val, n - 1));
}


/////0-1 knapSack with Bottom-Up method/////


int KnapSack_BottomUp() {
	int t[n + 1][W + 1];
	//initialisation(Base Condition)
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < n + 1; i++) t[0][i] = 0;

	//induction(replacing n,W with i,j from recursive code)
	if (wt[i - 1] <= j) {
		t[i][j] = max(val[i - 1] + t[i - 1][W - wt[i - 1]] , t[i - 1][j]);
	}
	else if (wt[i - 1] > j) {
		t[i][j] = t[i - 1][j];
	}
	return t[n][w];
}

//////////// Subset Sum Problem ////////////////

int arr[5] = "2,3,7,8,10";
int sum = 11;
int n = sizeof(arr);

//p.s. : if a subset exists whose total = sum

//recursive code

bool subset(int n, int arr[], int sum) {
	//base case
	if (sum == 0) return true;
	else if (n == 0 && sum > 0) return false;

	if (arr[n - 1] <= sum) {
		return subset(n - 1, arr, sum - arr[n - 1]) || subset(n - 1, arr, sum) ;
		//we are using OR instead of max
	}
	else {
		return subset(n - 1, arr, sum);
	}
}

//SubSetSum with bottom-up


bool isSubsetSum(vector<int>arr, int sum) {
	int i = arr.size();
	int j = sum;

	bool t[i + 1][j + 1];
	//initialization
	for (int a = 0 ; a < j + 1; a++) t[0][a] = false;
	for (int a = 0 ; a < i + 1; a++) t[a][0] = true;

	for (int a = 1; a < i + 1; a++) {
		for (int b = 1; b < j + 1; b++) {
			if (arr[a - 1] <= b) t[a][b] = t[a - 1][b - arr[a - 1]] || t[a - 1][b];

			else t[a][b] = t[a - 1][b];
		}
	}
	return t[i][j];
}

// Equal Sum Partition

bool EqualSumPart(vector<int> &arr) {
	int n = arr.size();
	int sum = 0;
	for (int i = 0; i < n ; i++) {
		sum += arr[i];
	}
	if (sum % 2 != 0) return false; // because the sum of both subset is same
	else if {
	return isSubsetSum(arr, sum / 2);
	}
}



// Count of SubSets sum with a given sum

int CountSubSetSum(vector<int> &arr, int sum) {
	int n = arr.size();
	int t[n + 1][sum + 1];

	//initialization
	for (int i = 0; i < sum + 1; i++) {
		t[0][i] = 0;
	}
	for (int i = 0; i < n + 1; i++) {
		t[i][0] = 1;
	}
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {
			if (arr[i - 1] <= j) {
				t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
				// here instead of OR('||') we use "+" to include all the previous
			}
			else {
				t[i][j] = t[i - 1][j];
			}
		}
	}
	return t[n][sum];
}


// Minimum SubSet Sum Difference*

int minDifference(int arr[], int n)  {
	int sum = 0;
	for (int i = 0 ; i < n ; i++) {
		sum += arr[i];
	}
	int col = sum / 2;
	//creating matrix for subset sum
	bool t[n + 1][col + 1];
	for (int i = 0 ; i < col + 1; i++) {
		t[0][i] = false;
	}
	for (int i = 0 ; i < n + 1; i++) {
		t[i][0] = true;
	}

	for (int i = 1; i < n + 1 ; i++) {
		for (int j = 1; j < col + 1; j++) {
			if (arr[i - 1] <= j) t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
			else t[i][j] = t[i - 1][j];
		}
	}
	// table complete

	//checking highest possible value for S1
	for (int a = col ; a >= 0; a--) {
		if (t[n][a] == true) return (sum - (2 * a));
	}
}


// Count of Subsets with a given difference

int CountSubSetDiff(int arr[], n, diff) {
	int sum , sum1;
	for (int i = 0; i <= n; i++) sum += arr[i];

	sum1 = (sum + diff) / 2;

	t[n + 1][sum1 + 1];
	// matrix for count of subset sum

	return t[n][sum1];
}


// TargetSum*

int findTargetSumWays(vector<int>& arr, int diff) {
	// similar to countSubsetSumDiff
	int n = arr.size();
	int sum = 0 ;
	for (int i = 0; i < n; i++) sum += arr[i];
	if (abs(diff) > sum || (diff + sum) % 2 != 0) return 0;
	int sum1 = (sum + diff) / 2;

	int t[n + 1][sum1 + 1]; // matrix to count Subset
	for (int i = 0 ; i < sum1 + 1 ; i++) t[0][i] = 0;
	for (int i = 0 ; i < n + 1; i++) t[i][0] = 1;

	for (int i = 1 ; i < n + 1 ; i++) {

		// *****IMPORTANT******
		//here 'j' starts from 0 because 0 in arr is valid
		for (int j = 0 ; j < sum1 + 1; j++) {
			if (arr[i - 1] <= j) t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
			else t[i][j] = t[i - 1][j];
		}
	}
	return t[n][sum1];
}


///// Un-bounded KnapSack //////

if (wt[i - 1] <= j) {
	t[i][j] = max(val[i - 1] + t[i][W - wt[i - 1]] , t[i - 1][j]);
}					//		     |
//		Variation here(instead of [i-1])
else if (wt[i - 1] > j) {
	t[i][j] = t[i - 1][j];
}

// Rod- Cutting Problem
int cutRod(int price[], int n) {
	int length[n];
	for (int i = 0; i < n; i++) length[i] = i + 1;
	int t[n + 1][n + 1]; // t[price.size() + 1][LengthofRod + 1]
	for (int i = 0; i < n + 1; i++) t[0][i] = 0 ;
	for (int i = 0; i < n + 1; i++) t[i][0] = 0 ;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (length[i - 1] <= j) t[i][j] = max(price[i - 1] + t[i][j - length[i - 1]] , t[i - 1][j]);
			else t[i][j] = t[i - 1][j];					//  |
		}   											// variation(from 0/1 knapsack)
	}
	return t[n][n];
}

// Coin Change-I -> no. of ways

int coinchange(int amount, vector<int>& coins) {
	/*sum = amount
	same as SubSetSum count
	*/
	int n = coins.size();
	int t[n + 1][amount + 1];
	for (int i = 0; i < amount + 1; i++) t[0][i] = 0;
	for (int i = 0; i < n + 1; i++) t[i][0] = 1;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < amount + 1; j++) {
			if (coins[i - 1] <= j) t[i][j] = t[i][j - coins[i - 1]] + t[i - 1][j];
			/*	   |
			 here taking 'i' instead 'i-1'
			 because we can take any number of particular coin*/
			else t[i][j] = t[i - 1][j];
		}
	}
	return t[n][amount];
}

// Coin Change II -> min. no. of coins

int coinChange(vector<int>& coins, int amount) {
	int n = coins.size();
	long long int t[n + 1][amount + 1];
	for (int i = 0; i < amount + 1; i++) t[0][i] = amount + 1;
	//we are takin value > amount because it is not possible when n=0 or infinite amount of coins are needed
	//or here we can use INT_MAX-1 to prevent int overflow
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < amount + 1; j++) {
			if (coins[i - 1] <= j) t[i][j] = min(t[i][j - coins[i - 1]] + 1 , t[i - 1][j]);
			else t[i][j] = t[i - 1][j];
		}
	}
	if (t[n][amount] > amount) return -1; //this means not possible to create the amount
	else return t[n][amount];
}


//        *************** LONGEST COMMON SUBSEQUENCE(LCS)

// recursive code: gives TLE
int LCS(string text1, string text2) {
	int n = text1.length(), m = text2.length();
	//base case
	if (n == 0 || m == 0) return 0;

	//induction
	if (text1[n - 1] == text2[m - 1]) {
		text1.pop_back();
		text2.pop_back();
		return 1 + LCS(text1, text2);
	}
	else {
		string temp1 = text1, temp2 = text2;
		temp1.pop_back();
		temp2.pop_back();
		return max(LCS(text1, temp2), LCS(temp1, text2));
	}
}

// LCS with Bottom-Up :

int longestCommonSubsequence(string text1, string text2) {
	int n = text1.length(), m = text2.length();
	int t[n + 1][m + 1];
	//initialization
	for (int i = 0; i < m + 1; i++) t[0][i] = 0;
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	//matrix
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1 ; j++) {
			if (text2[j - 1] == text1[i - 1]) {
				t[i][j] = t[i - 1][j - 1] + 1;
			}
			else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
				// |
				//kyunki longest subsequence chahiye
			}
		}
	}
	return t[n][m];
}

// Longest common substring

int longestCommonSubstr(string S1, string S2, int n, int m) {
	int t[n + 1][m + 1];
	//initialization
	for (int i = 0; i < m + 1; i++) t[0][i] = 0;
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	//matrix
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1 ; j++) {
			if (S2[j - 1] == S1[i - 1]) t[i][j] = t[i - 1][j - 1] + 1;
			else t[i][j] = 0;
		}
	}
	int val = 0;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m + 1 ; j++) val = max(val, t[i][j]);
	}
	return val;
}

// Print the longest common subsequence

int PrintLCSubSequence(string a; string b; int n; int m) {
	// first form 't' matrix from lcs
	int t[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < m + 1; i++) t[0][i] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (a[i - 1] == b[j - 1]) t[i][j] = 1 + t[i - 1][j - 1];
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	// now traversing the matrix for LCS
	int i = n, j = m;
	string s = "";
	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			s.push_back(a[i - 1]);
			i--; j--;
		}
		else {
			if (t[i - 1][j] > t[i][j - 1]) i--;
			else j--;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

// Shortest Common SuperSequence

int LengthCommonSubSequence(string x, string y) {
	int n = x.length(); m = y.length();
	int a = longestCommonSubsequence(x, y);

	return n + m - a;
	//check note
}

// Minimum no. of insertion and deletion to convert string a to b

int MinimumInsrtDelConvert(string a, string b) {
	int n = a.length() , m = b.length();
	int a = longestCommonSubsequence(a, b);

	return m + n - (2 * a);
}

// Longest palandromic SubSequence*

int longestPalinSubseq(string s) {
	string s1 = s;
	reverse(s1.begin(), s1.end());
	int n = s.length();
	//now just find LCS b/w str s and it's reverse
	int t[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < n + 1; i++) t[0][i] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == s1[j - 1]) t[i][j] = t[i - 1][j - 1] + 1;
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return t[n][n];
}

// Minimum Insertion/Deletion in a string to make it palindrome

int minInsertions(string s) {
	string s1 = s;
	reverse(s1.begin(), s1.end());
	int n = s.length();

	int t[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < n + 1; i++) t[0][i] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == s1[j - 1]) t[i][j] = t[i - 1][j - 1] + 1;
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}// Find length of LPS of str 's' and substr it with length of string 's',
	//because there already is a palindrome in the str we just
	//need to insert/delete certain char to make the whole str plindrome
	return n - t[n][n];
}


// Print SCS(shortest supersequence)

//Function to find length of shortest common supersequence of two strings.
int shortestCommonSupersequence(string X, string Y, int n, int m)
{
	int t[n + 1][m + 1];
	//form the LCS matrix and then traverse it;
	//LCS(X,Y);
	int i = n, j = m;
	string val = "";
	while (i > 0 || j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			val.push_back(X[i - 1]);
			i--; j--;
		}
		else { //difference from LCS is that we also add the char to the str in who's
			//direction we are not moving. because we also have to add the char which are not
			//in LCS
			if (t[i][j - 1] > t[i - 1][j]) {
				val.push_back(Y[j - 1]);
				j--;
			}
			else {
				val.push_back(X[i - 1]);
				i--;
			}
		}
	}
	reverse(val.begin(), val.end());
	cout << val;
	return val.length();
}

//Length of Longest Repeating SubSequence

int LongestRepeatingSubsequence(string str) {
	int n = str.length();
	int t[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < n + 1; i++) t[0][i] = 0;
	//index of the repeating subsequence can't be same
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (str[i - 1] == str[j - 1] && i != j)t[i][j] = t[i - 1][j - 1] + 1;
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return t[n][n];
}

//Sequence Pattern matching

/*here we can just check if str s is a subsequence of str t by taking LCS of both and if
length of LCS == s.length()
OR we can perform 2 pointer method also.*/
bool isSubsequence(string s, string t) {
	int n = s.length(), m = t.length();
	//int minlength = min(s.length(),t.length());

	int tm[n + 1][m + 1];
	for (int i = 0; i < n + 1; i++) tm[i][0] = 0;
	for (int i = 0; i < m + 1; i++) tm[0][i] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (s[i - 1] == t[j - 1]) {tm[i][j] = 1 + tm[i - 1][j - 1];}
			else {tm[i][j] = max(tm[i][j - 1], tm[i - 1][j]);}
		}
	}
	if (tm[n][m] == n) return true;
	return false;
}

// Minimum insertions for string to palindrome

//first come to conclusion that it is a DP question and that too variation of LCS.
int minInsertions(string s) {
	string s1 = s;
	reverse(s1.begin(), s1.end());
	int n = s.length();

	int t[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++) t[i][0] = 0;
	for (int i = 0; i < n + 1; i++) t[0][i] = 0;

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s[i - 1] == s1[j - 1]) t[i][j] = t[i - 1][j - 1] + 1;
			else t[i][j] = max(t[i - 1][j], t[i][j - 1]);
		}
	}
	return n - t[n][n];
};/*find the length of longest pallindromic subsequence in str s and substract it
with length of str s, because there already is a palindrome in the str we just
need to insert certain char to make the whole str plindrome*/


// MATRIX CHAIN MULTIPLICATION

//memoization

int static t[101][101];

class Solution {
public:
	int solve(int arr[], int i, int j) {
		if (i >= j) return 0;
		if (t[i][j] != -1) return t[i][j];
		int mn = INT_MAX;
		for (int k = i; k <= j - 1; k++) {
			int tempans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
			if (tempans < mn) mn = tempans;
		}
		return t[i][j] = mn;
	}

	int matrixMultiplication(int N, int arr[])
	{
		memset(t, -1, sizeof(t));
		solve(arr, 1, N - 1);
	}
};


/// *****************Removal Game *************

vector<long long> arr;
long long dp[5005][5005][2];
long long solve(long long i, long long j, long long flag) {
	if (i > j) return 0;
	if (dp[i][j][flag] != -1) return dp[i][j][flag];
	if (flag == 1) {
		long long x = arr[i] + solve(i + 1, j, 0);
		long long y = arr[j] + solve(i, j - 1, 0);
		//adding here beacuse it adds to player1's sum
		return dp[i][j][flag] = max(x, y);
	}
	else {
		long long x = -arr[i] + solve(i + 1, j, 1);
		long long y = -arr[j] + solve(i, j - 1, 1);
		//subtracting here because it adds in player2's sum
		return dp[i][j][flag] = min(x, y);

	}
}

int main() {
	fast;
	long long n;
	cin >> n;
	long long total = 0;
	f(i, n) {
		long long x;
		cin >> x;
		total += x;
		arr.push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	cout << (solve(0, n - 1, 1) + total) / 2;
	// from solve(0,n-1,1) we get sum1 - sum2 ans from total we get sum1+sum2
	// and we need sum1
	return 0;
}