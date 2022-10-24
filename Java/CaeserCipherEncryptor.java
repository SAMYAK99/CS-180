class CaeserCipherEncryptor {

	static String solve(String str, int key) {
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) + key <= 122)
				sb.append((char)(str.charAt(i) + key));
			else
				sb.append((char)(96 + (str.charAt(i) + key) % 122));
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		String str = "abz";
		System.out.println(solve(str, 2));

	}
}