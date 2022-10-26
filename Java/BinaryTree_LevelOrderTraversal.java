package DSA;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BinaryTree_LevelOrderTraversal {
    static BNode create(){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter data:");
        int data=sc.nextInt();
        if(data==-1){
            return null;
        }
        BNode root=new BNode(data);
        System.out.println("Enter left for "+ data);
        root.left=create();
        System.out.println("Enter right for "+data);
        root.right=create();
        return root;
    }
    static void  LOT(BNode root){
        Queue<BNode>n=new LinkedList<>();
        n.add(root);
        //n.add(null);

        while(!n.isEmpty()){
            BNode cur=n.poll();
            //to print every level in new line
//            if(cur==null){
//                if(n.isEmpty()){
//                    return;
//                }
//                n.add(null);
//                System.out.println();
//                continue;
//            }
            System.out.print(cur.data+" ");
            if(cur.left!=null){
                n.add(cur.left);
            }
            if(cur.right!=null){
                n.add(cur.right);
            }
        }

    }
    public static void main(String[] args) {
        BNode k=create();
        LOT(k);

    }
}
