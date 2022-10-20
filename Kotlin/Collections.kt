fun main(){

    // Immutable List - Items added cannot be added or removed
    // by default list are immutable
    val names = listOf<String>("Alan","Walker","DareDevil")
    println("Size of List : ${names.size}")
    println("Second Member ${names.get(1)}")    // names[1]
    println("Index of Second member is ${names.indexOf("Walker")}")



    // Mutable List - Items can be added
    val name = mutableListOf<Int>(1,2,3,4,5)
    name.add(6)
    name.removeAt(2)
    println(name)
    name.clear()
    println(name)



    //Immutable Set - Contains unique elements
    val nameSet = setOf<Int>(1,2,3,4)



    // Mutable Set
    val nameMutSet = mutableSetOf<Int>(1,2,3)
    nameMutSet.add(4)
    nameMutSet.add(1)            // Duplicate elements will be rejected
    println(nameMutSet)


    // Immutable Map -
    val  nameClass = mutableMapOf(1 to "Varun" , 2 to "Tanya" )
    nameClass.put(3 , "Ram")               // Adding the values in the map
    nameClass.remove(2)
    println("Values : ${nameClass.values}")
    println("Items : ${nameClass.keys}")




}
