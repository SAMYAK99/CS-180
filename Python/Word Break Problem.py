def wordBreak(wordList, word):
	if word == '':
		return True
	else:
		wordLen = len(word)
		return any([(word[:i] in wordList) and wordBreak(wordList, word[i:]) for i in range(1, wordLen+1)])
