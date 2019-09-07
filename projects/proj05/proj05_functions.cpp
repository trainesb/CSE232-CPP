/*
Project05
wfp 02/24/2018 sec010

Program will encode and decode a msg given two keywords.
* 
Clean_string function changes a string to lower case containg only alpha

create_encoding() will make the grids for the keywords given. No repeat 
letters, and alphabetical after the keyword
* 
encoding_diagraph() will take a msg and return the encoded virsion
* 
decode_diagraph() takes a encoded msg and decodes it using two keywords
* 
encode() formats and submits paramters to encoding_diagraph() which 
* returns a coded string
* 
decode() foramts amd submits a coded msg to be decoded by 
* decode_diagraph()
*/

#include<string>
using std::string;
#include<iostream>
using std::endl; using std::cout; using std::cin;


string clean_string(string s){
	string clean;
	for(auto a: s){
		if(isalpha(a)){
			clean += tolower(a);
		}
	}
	return clean;
}

string create_encoding(string key){
	string ck, alphabet="abcdefghijklmnoprstuvwxyz";
	int index, del, d;
	d = key.find('q');
	if(d != string::npos)
		key = key.erase(d,1);
	key = clean_string(key);
	cout<<"key: "<<key<<endl;
	for(auto chr: key){
		index = ck.find(chr);
		cout<<"index: "<<index<<endl;
		if (index == string::npos){
			ck += chr;
			del = alphabet.find(chr);
			alphabet = alphabet.erase(del, 1);
			cout<<"ck: "<<ck<<endl;
		}
	}
	return ck+alphabet;
}


string encode_digraph(string dg, string block1, string block2){
	long index, indextwo, row, col, rowtwo, coltwo,first, second;
	string list, alphabet="abcdefghijklmnoprstuvwxyz", resault;
	for(string::size_type i=0; i<dg.size(); ++i){
		list = dg[i];
		list += dg[i+1];
		i+=1;
		cout<<"list: "<<list<<endl;
		index = alphabet.find(list[0]);
		indextwo = alphabet.find(list[1]);
		cout<<"index: "<<index<<endl;
		cout<<"index2: "<<indextwo<<endl;
		row = index/5;
		rowtwo = indextwo /5;
		cout<<"row: "<<row<<endl;
		cout<<"row2: "<<rowtwo<<endl;
		col = index%5;
		coltwo = indextwo%5;
		cout<<"col: "<<col<<endl;
		cout<<"col2: "<<coltwo<<endl;
		first = (row*5)+coltwo;
		second =(rowtwo*5)+col;
		cout<<"first: "<<first<<endl;
		cout<<"second: "<<second<<endl;
		resault += block1[first];
		resault += block2[second];
		cout<<"resault: "<<resault<<endl;
		cout<<endl;
	}
	return resault;
}


string decode_digraph(string dg, string block1, string block2){
	long index, index2, row, row2, col, col2, first, second;
	string list, resault, alphabet="abcdefghijklmnoprstuvwxyz";
	for(string::size_type i=0; i<dg.size(); ++i){
		list = dg[i];
		list += dg[i+1];
		i+=1;
		index = block1.find(list[0]);
		index2 = block2.find(list[1]);
		row = index/5;
		row2 = index2/5;
		col = index%5;
		col2 = index2%5;
		first = row*5+col2;
		second = row2*5+col;
		resault += alphabet[first];
		resault += alphabet[second];

		
	}
	return resault;
}


string encode(string msg, string key1, string key2){
	long size;
	string resault, block1, block2;
	msg = clean_string(msg);
	size =msg.size();
	if (size%2!=0)
		msg += 'x';
	cout<<"msg: "<<msg<<endl;
	block1 = create_encoding(key1);
	block2 = create_encoding(key2);
	resault = encode_digraph(msg, block1, block2);
	return resault;
}


string decode(string msg, string key1, string key2){
	string resault, block1, block2;
	msg = clean_string(msg);
	block1 = create_encoding(key1);
	block2 = create_encoding(key2);
	resault = decode_digraph(msg, block1, block2);
	return resault;
}


int main(){
	string s="Test String", a="example", c="keyword", dg="squarespace", gd="fyfy";
	cout<<"encode: "<<create_encoding(dg)<<endl;
	cout<<endl;

	
}
