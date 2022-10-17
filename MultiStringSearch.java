import java.util.*;

class MultiStringSearch {

	// *** Approach One ***

	static class ModifiedSuffixTrie {

		static class TrieNode {
			HashMap<Character, TrieNode> children;

			TrieNode() {
				children = new HashMap<>();
			}

		}

		static TrieNode root = new TrieNode();

		static void TriePopulate(String str) {

			for (int i = 0; i < str.length(); i++)
				insertSubstringFrom(i, str);

		}

		static void insertSubstringFrom(int i, String str) {

			TrieNode node = root;

			for (int j = i; j < str.length(); j++) {

				char letter = str.charAt(j);

				if (!node.children.containsKey(letter))
					node.children.put(letter, new TrieNode());

				node = node.children.get(letter);
			}

		}

		static boolean contains(String str) {

			TrieNode node = root;

			for (int i = 0; i < str.length(); i++) {
				char letter = str.charAt(i);
				if (!node.children.containsKey(letter))
					return false;
				node = node.children.get(letter);
			}

			return true;
		}
	}

	//O(b^2+ns) time | O(b^2+ns) space

	static void ApproachOne(String bigString, String []smallStrings) {
		ModifiedSuffixTrie trie = new ModifiedSuffixTrie();
		trie.TriePopulate(bigString);
		for (String i : smallStrings)
			System.out.println(trie.contains(i));
	}


	// *** Appproach Two ***

	static class TrieNode {
		HashMap<Character, TrieNode> children;
		String string;

		TrieNode() {
			children = new HashMap<>();
			string = "";
		}
	}

	static TrieNode root = new TrieNode();

	static void insert(String str) {
		TrieNode node = root;
		for (int i = 0; i < str.length(); i++) {
			char letter = str.charAt(i);
			if (!node.children.containsKey(letter))
				node.children.put(letter, new TrieNode());

			node = node.children.get(letter);
		}
		node.string = str;
	}

	// O(ns+bs) time | O(ns) space
	static void ApproachTwo(String bigString, String[]smallStrings) {

		for (String i : smallStrings)
			insert(i);

		Map<String, Boolean> containedStrings = new HashMap<>();
		for (int i = 0; i < bigString.length(); i++)
			findSmallString(bigString, i, containedStrings);

		for (String i : smallStrings) {
			if (!containedStrings.containsKey(i))
				containedStrings.put(i, false);
		}

		System.out.println(containedStrings);
	}

	static void findSmallString(String bigString, int i, Map<String, Boolean> containedStrings) {

		TrieNode node = root;

		for (int j = i; j < bigString.length(); j++) {

			char letter = bigString.charAt(j);

			if (!node.children.containsKey(letter))
				break;

			node = node.children.get(letter);

			if (node.string != "")
				containedStrings.put(node.string, true);
		}
	}

	public static void main(String[] args) {
		String bigString = "this is a big String";
		String []smallStrings = {"this", "yo", "is", "bigger", "String", "hello"};
		ApproachTwo(bigString, smallStrings);
	}
}