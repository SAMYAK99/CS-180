fun main(args: Array<String>) {

    var firstnum = 1.20f
    var secondnum = 2.45f

    println("Before swapping")
    println("First number = $firstnum")
    println("Second number = $secondnum")

    val temporary = firstnum

    firstnum = secondnum

    secondnum = temporary

    println("After swapping")
    println("First number = $firstnum")
    println("Second number = $secondnum")
}