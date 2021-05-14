#include <bits/stdc++.h>

using namespace std;

template<class X> class matrix {
public:
	int row, column;
	vector<vector<X>> M;
	matrix(vector<vector<X>> MM) : row ((int)MM.size()), column ((int)MM.size), M(MM) {}
	matrix (int r) : row (r), column (r), M (vector<vector<X>> (row, vector<X> (column))) { for (int i = 0; i < row; i++) M[i][i] = X(1); }
	matrix(int r , int c) : row (r), column (c), M (vector<vector<X>> (row, vector<X> (column))) {}
	matrix(int r , int c , X value) : row (r), column (c), M (vector<X> (row, vector<X> (column, value))) {}
	vector<X>& operator [] (int idx) {
		if(idx < 0 || idx >= row) { throw out_of_range("In matrix : " + to_string(idx) + " is out of range [0 , " + to_string(row - 1) + "]"); }
		return M[idx];
	}
	template<class T> ostream& operator << (matrix<T> a);
	matrix operator + (matrix b);
	matrix operator - (matrix b);
	matrix operator * (matrix b);
	matrix operator / (matrix b);
	matrix operator + (X b);
	matrix operator - (X b); 
	matrix operator * (X b); 
	matrix operator / (X b); 
	matrix operator ^ (int64_t b);
	void operator += (matrix a);
	void operator -= (matrix a);
	void operator *= (matrix a);
	void operator /= (matrix a);
	void operator += (X b);
	void operator -= (X b); 
	void operator *= (X b); 
	void operator /= (X b); 
	void operator ^= (int64_t b);
	bool operator == (matrix a);
	bool operator != (matrix a);
	matrix transpose();
};
template<class T> ostream& operator << (ostream& out , matrix<T> a) {
	int row = a.row, column = a.column;
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) out << a[i][j] << ' ';
		out << " \n"[i != row - 1]; 
	}
	return out;
}
template<class X> matrix<X> matrix<X>::operator + (matrix<X> b) {
	if(row != b.row || column != b.column) { throw logic_error("Addition of matrices with different Dimensions"); }
	for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] += b[i][j]; } 
	return *this;
}
template<class X> matrix<X> matrix<X>::operator - (matrix<X> b) {
	if(row != b.row || column != b.column) { throw logic_error("Subtraction of matrices with different Dimensions"); }
	for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] -= b[i][j]; }
	return *this;
}
template<class X> matrix<X> matrix<X>::operator * (matrix<X> b) {
	if(column != b.row) { throw logic_error("Multiplication of martices with different Dimensions"); }
	int r = row, col = b.column;
	matrix<X> ret(r , col);
	for(int i = 0; i < r; i++) { for(int j = 0; j < col; j++) { for(int k = 0; k < column; k++) ret[i][j] += (M[i][k] * b[k][j]); } }
	return ret;
}
template<class X> matrix<X> matrix<X>::transpose() {
	if (row != column) { throw logic_error("Cannot Transpose an NON-SQUARE matrix"); }
	matrix<X> ret(column , row); 
	for(int i = 0; i < column; i++) { for(int j = 0; j < row; j++) { ret[i][j] = M[j][i]; } } 
	return ret; 
}
template<class X> matrix<X> matrix<X>::operator / (matrix<X> b) { return *this * inv(b); }
template<class X> matrix<X> matrix<X>::operator + (X b) 				{ return *this + matrix(row , column , b); }
template<class X> matrix<X> matrix<X>::operator - (X b) 				{ return *this - matrix(row , column , b); }
template<class X> matrix<X> matrix<X>::operator * (X b) 				{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] *= b; } return *this; }
template<class X> matrix<X> matrix<X>::operator / (X b) 				{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) M[i][j] /= b; } return *this; }
template<class X> matrix<X> matrix<X>::operator ^ (int64_t b) 	{ matrix<X> ret = *this, a = *this; b--; while(b) { if(b % 2 == 1) ret = ret * a; a = a * a, b /= 2; } return ret; }
template<class X> void matrix<X>::operator += (matrix<X> b) 		{ *this = *this + b; }
template<class X> void matrix<X>::operator -= (matrix<X> b) 		{ *this = *this - b; }
template<class X> void matrix<X>::operator *= (matrix<X> b) 		{ *this = *this * b; }
template<class X> void matrix<X>::operator /= (matrix<X> b) 		{ *this = *this / b; }
template<class X> void matrix<X>::operator += (X b) 						{ *this = *this + b; }
template<class X> void matrix<X>::operator -= (X b) 						{ *this = *this - b; }
template<class X> void matrix<X>::operator *= (X b) 						{ *this = *this * b; }
template<class X> void matrix<X>::operator /= (X b) 						{ *this = *this / b; }
template<class X> void matrix<X>::operator ^= (int64_t b) 			{ *this = *this ^ b; }
template<class X> bool matrix<X>::operator == (matrix<X> a) 		{ for(int i = 0; i < row; i++) { for(int j = 0; j < column; j++) if(M[i][j] != a[i][j]) return false; } return true; }
template<class X> bool matrix<X>::operator != (matrix<X> a) 		{return !(*this == a);}

// int64_t fibo_mat(int64_t n) {
// 	matrix<int64_t> a(1 , 2 , 1);
// 	a[0][0] = 0;
// 	matrix<int64_t> P(2 , 2 , 1);
// 	P[0][0] = 0;
// 	P ^= n;
// 	a *= P;
// 	return a[0][0];
// }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	return 0;
}
