#include <iostream>
#include <string>

using namespace std;

// Node is a data structure that represents a single node in a trie.
class Node {
public:
	Node* children[27]; // 26 letters in the alphabet
	bool isEnd; // isEnd is true if the node represents the end of a word
	// Constructor for Node class that initializes all children to NULL and isEnd to false.
	Node() {
		for (int i = 0; i < 27; i++) {
			children[i] = NULL;
		}
		isEnd = false;
	}
};
// Trie is a tree data structure used for efficient retrieval of a key in a large data set of strings.
class Trie {
	Node* root;
public:
	// Constructor for Trie class that initializes the root to a new Node.
	Trie() {
		root = new Node();
	}
	// insert inserts a word into the trie.
	void insert(string word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); i++) {
			int index = word[i] - 'a';
			if (word[i] == '$') {
				index = 26;
			}
			if (curr->children[index] == NULL) {
				curr->children[index] = new Node();
			}
			curr = curr->children[index];
		}
		curr->isEnd = true; // mark the end of the word
	}
	// search returns true if the word is in the trie and false otherwise.
	bool search(string word) {
		Node* curr = root;
		for (int i = 0; i < word.size(); i++) {
			int index = word[i] - 'a';
			if (word[i] == '$') {
				index = 26;
			}
			// if the current character is not in the trie, return false
			if (curr->children[index] == NULL) {
				return false;
			}
			curr = curr->children[index];
		}
		// if the current node is not the end of a word, return false
		if (curr->isEnd == false) {
			return false;
		}
		return true;
	}
};
class SuffixTrie {
	Trie t;
public:
	void insert(string text) {
		text += "$";
		for (int i = 0; i < text.size(); i++)
		{
			t.insert(text.substr(i, text.size()));
		}
	}
	bool search(string text) {
		text += "$";
		return t.search(text);
	}
};
int main() {
	SuffixTrie t;
	t.insert("hello");
	t.insert("world");
	cout << t.search("hello") << endl;
	cout << t.search("ello") << endl;
	cout << t.search("world") << endl;
	cout << t.search("wor") << endl;
}