import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

class first {
    public static void main(String[] args) {
        List<Integer> list = new LinkedList<>();
        list.add(2);
        list.add(3);
        list.add(7);
        list.add(3);
        list.add(4);
        list.add(3);
        list.add(3);
        list.add(3);

        System.out.print(majorityElement(list));
    }

    public static int majorityElement(final List<Integer> A) {
        int target = (int)Math.floor(A.size() / 2);
        Map<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<A.size(); i++) {
            if(map.containsKey(A.get(i))) {
                map.replace(A.get(i), map.get(A.get(i)) + 1);
            } else {
                map.put(A.get(i), 1);
            }
        }

        for(Integer key: map.keySet()) {
            if(map.get(key) > target) {
                return key;
            }
        }
        return -1;
    }
    
}