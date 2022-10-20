fun main() {

    //Null Safety in Kotlin can be achieved with the help of three operators,
    // the safe call operator (?),
    // the Elvis operator (?:)
    // and the not-null assertion operator (!!) operator.


    //null can't be assigned to a String
    // val name : String = null

    val name : String ? =  null
    // Safe Call Operator ?.
    // - If a variable is null it will return null Otherwise normal call
    println(name ?. length)            // prints null


    // Elvis Operator ?:
    // Ternary or If Else for null operator
    println(name ?. length ?: 0)         // prints 0


    // Non Null Assertion Operator !!
    // Defeats the purpose of null safety
    //   println(name !! .length)    //suppresses the compilation error
    //the above statement in this case however, will prompt a run-time


}
