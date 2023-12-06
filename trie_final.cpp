
#include<bits/stdc++.h>

using namespace std;

//user-defined data type to create a trie node.
struct node{

	node* links[26];
	
	int endWith=0;			//this variable will store the total number of same words.
	
	int prefixCount=0;		//this variable will store the count of the words which begins with same prefix.
	
	
	//member functions.
	
	//Below function will return if char is present.
	bool isLetterPresent( char ch ){
	
		return links[ ch-'a' ] != NULL;
	
	}
	
	//Below function will create a trie-node for a given character.
	void setLetter( char ch ){
		
		node* newnode = new node();
		
		links[ ch-'a' ] = newnode;
	}
	
	//Below function will return the pointer of the given character.
	node* getNext( char ch ){
		
		return links[ ch-'a' ];
	
	}
	
	//Below function will just increase prefix count.
	void incrementPrefixCount( void ){
	
		prefixCount++;
	
	}
	
	//Below function will just decrease prefix count.
	void decrementPrefixCount( void ){
	
		prefixCount--;
	
	}
	
	//Below function will just increase endWith count.
	void incrementEndCount( void ){
	
		endWith++;
	
	}
	
	//Below function will just decrease endwith count.
	void decrementEndCount( void ){
	
		endWith--;
	
	}
	
	//Below function will just send total prefix count till current word.
	int getPrefixCount( void ){
	
		return prefixCount;	
		
	}
	
	//Below function will just send total number of same word.
	int getEndCount( void ){
	
		return endWith;	
		
	}
	
};




//making a blueprint for trie.
class trie{

	node*root;	//This will hold starting address each trie object.

public:

	trie(){	
	
		root = new node();	//complier will supply this default constructor.. so each pointer to the links will point to NULL.
	
	}
	
	//Below function will insert a word in the trie data structure.
	void insert( string word ){
		
		node* temp = root;	//temp pointer will traverse through trie nodes.
		
		int n = word.size();
		
		for( int i = 0 ; i < n; i++ ){
		
			if( !temp->isLetterPresent( word[i] ) ){ 	//if the letter is not present.
			
				temp->setLetter( word[i] );		//insert the letter in the trie.
			}
			
			temp = temp->getNext( word[i] ); 	//go to the next trie-node of given character.
			
			temp->incrementPrefixCount();	//It'll just insrease prefixCount till current word.
		
		}
		
		temp->incrementEndCount();	//It'll increase the endCount and that indicates the total number of same given word.
		
	}
	
	//Below function will return how many "word" is present. 
	int search( string word ){
	
		node* temp = root;	//as usual this pointer will traverse through trie nodes.
		
		int n = word.size();
		
		for( int i = 0 ; i < n ; i++ ){
			
			if( !temp->isLetterPresent( word[i] ) ) return false;  //If the letter is not present then surely the word does not exist.
			
			temp = temp->getNext( word[i] );	//go to the next trie-node of given character.	
			
		}
		
		return temp->getEndCount();	//If this is zero that means the word is not exist oteriwse return true.
		
	}
	
	//Below function will return how mant words start with given string.
	int startWith( string word){
		
		node* temp = root; 	//Traversal pointer
		
		int n = word.size();
		
		for( int i = 0 ; i < n ; i++ ){
		
			if( !temp->isLetterPresent( word[i] ) ) return 0;	//if the word is not present then return 0.
			
			temp = temp->getNext( word[i] );	//go to the next trie-node of that character.
			
		}
		
		return temp->getPrefixCount();	//return how many of them have same prefix.
		
	}
	
	//Below function will erase the given word by 1 time when the word exist in the trie.
	void erase( string word ){
	
		if( !search( word ) ){			//If the word is not prenset.
		
			cout<<word<<" is not present in the trie."<<endl;	
			
			return;
			
		}	
		
		node* temp = root;	//traversal pointer.
		
		int n = word.size();
		
		for( int i = 0 ; i < n ; i++ ){
		
			temp = temp->getNext( word[i] );	//go the the trie node of word[i].
			
			temp->decrementPrefixCount();	//decrease the prefix count by 1 in the prent trie node.
		
		}
		
		temp->decrementEndCount();	//decrease the end count by 1.
		
	}
	
};


int main(){

	trie t;
	t.insert("Tanit");
	t.insert("Tanit");
	t.insert("ranuo");
	t.insert("Neha");
	cout<<t.search("Tanit")<<endl<<t.startWith("ranu")<<endl;
	t.erase("Tanit");
	cout<<t.search("Neha")<<endl;
	
	return 0;
}
