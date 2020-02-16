#include <iostream>
#include <stdlib.h>

template <typename T>
class Matrica {
	private: 
	int rows;
	int cols;
	T** val;
	class Row;
	public:
		Matrica( int n, int m): rows(n), cols(m){
			val = new T*[rows];
			for(int i=0; i<rows; ++i){
				val[i] = new T[cols];
			}
		}
		Matrica(Matrica<T> &&m) {
			rows = m.rows;
			cols = m.cols;
			val=m.val;
			m.rows = 0;
			m.cols = 0;
			m.val = 0;
		}
		Matrica(const Matrica<T>& m){
			rows=m.rows;
			cols=m.cols;
			val=m.val;
		}
		void deleteMatrix(){
			delete[] val;
		}
		int countNull(){
			int count = 0;
			for(int i = 0; i < rows; ++i){
				for(int j = 0; j < cols; ++j){
					if(val[i][j]==0) count++;
				}
			}
			return count;
		}
		~Matrica(){
			deleteMatrix();
			}
		void randomFill(){
			for (int i=0; i<rows; i++) {
				for (int j=0; j<cols; j++) {
					val[i][j] = rand() % 10;
				}
				}
			}
		template <typename U>
		friend bool operator ==(const Matrica<U> &m1, const Matrica<U> &m2);
		template <typename Z>
		friend bool operator !=(const Matrica<Z> &m1, const Matrica<Z> &m2);
		template <typename Y>
		friend std::ostream& operator <<(std::ostream &out,Matrica<Y> &a);
		Row operator [](int i){
				return (*this, i);
			}
	private:
		class Row{
			private:
				Matrica<T> &matrix;
				int row;
			public:
				Row(Matrica<T> &m, int r): matrix(m), row(r){}
				T& operator [](int c){
						return (matrix.val[row][c]);
					};
			};
	
};
template <typename U>
bool operator ==(const Matrica<U> &m1, const Matrica<U> &m2){
	bool x;
	if((m1.rows==m2.rows)&&(m1.cols==m2.cols)){
		for(int i=0; i<m1.rows; ++i){
			for(int j=0; j<m1.cols; ++j){
				if(m1.val[i][j]==m2.val[i][j]){
						x=true;
				}
				else{
					return false;
				}
			}
		}
		return x;
	}
	else{
		return false;
	}	
}
template <typename Z>
bool operator !=(const Matrica<Z> &m1, const Matrica<Z> &m2){
		return !(m1==m2);
	}
template <typename Y>
std::ostream& operator <<(std::ostream &out, Matrica<Y> &a) {
		for(int i=0; i<a.rows; ++i) {
			for(int j=0; j<a.cols; ++j) {
				out<<a.val[i][j]<<"  ";
			}
			out<<std::endl;
		}
		return out;
}
