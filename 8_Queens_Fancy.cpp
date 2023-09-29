#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool ok(int q[], int col) {
	for (int i = 0; i < col; i++)
		if (q[col] == q[i] || (col - i) == abs(q[col] - q[i]))
			return false;
	return true;
}

void backtrack(int& col) {
	col--;
	if (col == -1) {
		system("PAUSE");
		exit(1);
	}
}

void print(int q[]) {
	static int count = 0;
	cout << ++count << endl;
	typedef char box[5][7];
	box bb, wb, * board[8][8];
	char ws = char(219);
	box bq =
	{
		ws, ws, ws, ws, ws, ws, ws,
		ws, ' ', ws, ' ', ws, ' ', ws,
		ws, ' ', ' ', ' ', ' ', ' ', ws,
		ws, ' ', ' ', ' ', ' ', ' ', ws,
		ws, ws, ws, ws, ws, ws, ws
	};

	box wq =
	{
		' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ws, ' ', ws, ' ', ws, ' ',
		' ', ws, ws, ws, ws, ws, ' ',
		' ', ws, ws, ws, ws, ws, ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' '
	};
	for (int a = 0; a < 5; a++)
		for (int b = 0; b < 7; b++)
		{
			wb[a][b] = ' ';
			bb[a][b] = char(219);
		}
	for (int a = 0; a < 8; a++)
		for (int b = 0; b < 8; b++)
			if ((a + b) % 2 == 0) {
				if (q[a] == b) {
					board[a][b] = &wq;
				}
				else {
					board[a][b] = &wb;
				}
			}
			else {
				if (q[a] == b) {
					board[a][b] = &bq;
				}
				else {
					board[a][b] = &bb;
				}
			}

	cout << " ";
	for (int a = 0; a < 7 * 8; a++)
		cout << '_';
	cout << endl;
	for (int a = 0; a < 8; a++)
		for (int k = 0; k < 5; k++)
		{
			cout << " " << char(179);
			for (int b = 0; b < 8; b++)
				for (int l = 0;
					l < 7; l++)
					cout << (*board[a][b])[k][l];
			cout << char(179) << endl;
		}
	cout << " ";
	for (int a = 0; a < 7 * 8; a++)
		cout << char(196);
	cout << endl;
}
int main() {
	int q[8]; q[0] = 0;
	int c = 1;

	bool from_backtrack = false;

	while (true) {
		while (c < 8) {

			if (!from_backtrack)q[c] = -1;
			from_backtrack = true;

			while (q[c] < 8) {
				q[c]++;

				if (q[c] == 8) {
					from_backtrack = true;
					backtrack(c);
					break;
				}

				if (ok(q, c)) {
					from_backtrack = false;
					c++;
					break;
				}
			}

		}
		print(q);
		from_backtrack = true;
		backtrack(c);
	}
}
