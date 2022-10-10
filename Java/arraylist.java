import java.util.*;
public class arraylist
{
	public static void main(String[] args)
	{
		List<String> girls=new ArrayList();
		girls.add("janvi");
		girls.add("akshita");
		girls.add("vatsala");
		System.out.println(girls);
		girls.add(1,"shweta");
		System.out.println(girls);
		
		
		List<String> boys=new ArrayList();
		boys.add("nitin");
		boys.add("prince");
		boys.add("anuj");
		
		girls.addAll(boys);
		System.out.println(girls);
		System.out.println(girls.get(1));
		System.out.println(girls.size());
		
		
		girls.remove(1);
		System.out.println(girls);
		girls.removeAll(boys);
		System.out.println(girls);
		girls.remove(String.valueOf("janvi"));
		System.out.println(girls);
		girls.set(0,"saumya");
		System.out.println(girls);
		System.out.println(girls.contains("priyanshi"));
		
		girls.clear();
		System.out.println(girls);
		
		//output:-
		//[janvi, akshita, vatsala]
		//[janvi, shweta, akshita, vatsala]
		//[janvi, shweta, akshita, vatsala, nitin, prince, anuj]
		//shweta
		//7
		//[janvi, akshita, vatsala, nitin, prince, anuj]
		//[janvi, akshita, vatsala]
		//[akshita, vatsala]
		//[saumya, vatsala]
		//[]
		
		
		
		for(int i=0;i<boys.size();i++)
		{
			System.out.println(boys.get(i));
		}
		for(String x:boys)
		{
			System.out.println(x);
		}
		Iterator<String> i= boys.iterator();
		while(i.hasNext())
		{
			System.out.println(i.next());
		}
		/*
		output:-
		nitin
		prince
		anuj
		nitin
		prince
		anuj
		nitin
		prince
		anuj*/
				
		
		
		
		
		
		
	}
}