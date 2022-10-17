class Solution {
    public void recoverTree(TreeNode root) {
        TreeNode temp = null;

        while (root != null) {
            if (root.left == null) {
                System.out.println(root.val);
                root = root.right;
            } else {
                temp = root.left;
                while (temp.right != null && temp.right != root)
                    temp = temp.right;
                if (temp.right != null) {
                    System.out.println(root.val);
                    temp.right = null;
                    root = root.right;
                } else {
                    temp.right = root;
                    root = root.left;
                }
            }
        }
    }
}