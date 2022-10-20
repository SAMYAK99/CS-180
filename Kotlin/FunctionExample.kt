fun main() {

    // declaration
    nam("John")
    println(addNum(4, 5))

    // Named Arguments
    println(volume("Box Name",10,height = 20,breadth = 30))

    // Single Expression Functions
      println(addNumb(2,3))
}



  //Default Functions
    fun nam (name : String) : Unit{
        println(name)
    }
    fun addNum (x : Int , y : Int) : Int{
         return x + y
    }

   // Named Arguments
    fun volume(name : String ,length : Int , breadth : Int , height : Int ) : Int{
        println(name)
        return length * breadth * height
    }

    // Single Expression Functions
    fun addNumb(x:Int , y : Int) = x+y
