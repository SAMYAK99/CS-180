fun main(){


    // Type Conversion
    val g: Int = 10
    val h: Long = g.toLong()
    println(h)

    // Type Casting
    val name1: String = "Sam"
    val name2: String = name1 as String

    val x: Int = 7
//  val y : Long = x as Long     Error
    val z: Long? = x as? Long   // SafeCast Operator
    println(z)



}
