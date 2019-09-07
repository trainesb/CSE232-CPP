#include"VECOPS_H"

vector<long> vector_ops(const vector<long>& v1, const vector<long>& v2,
						char op){
							int size1, size2, smaller;
							vector<long> vctr;
							size1 = v1.size();
							size2 = v2.size();
							if (size1 >= size2)
								smaller = size2;
							else
								smaller = size1;
							for(int i=0; i<=(smaller-1); ++i){
									if(op='+'){
										vctr[i]=v1[i]+v2[i];
									}
									else if(op='-'){
										vctr[i]=v1[i]-v2[i];
									}
									else{
										return vctr;
									}
							}
							for(int n=smaller; n<size2; ++i){
								vctr.pushback(v2[n]);
							}
				
}


void print_vector (ostream& out, const vector<long>& v){
	for(auto element: v){
		out<<element<<endl;
	}
}

