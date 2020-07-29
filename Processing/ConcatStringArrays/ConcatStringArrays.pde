
import java.util.Arrays;

void setup()
{
  
  println("hello ");
  
  String[] numbers = new String[]{"one", "two", "three"};
  println(Arrays.toString(numbers));
  
  String[] numbers2 = new String[]{"four", "five"};
  println(Arrays.toString(numbers2));
  
  numbers = append2Array(numbers,numbers2);
  println(Arrays.toString(numbers));
  
}

// https://stackoverflow.com/a/52438829
public static <T> T[] append2Array(T[] elements, T[] newElements)
{
    T[] newArray = Arrays.copyOf(elements, elements.length + newElements.length);
    System.arraycopy(newElements, 0, newArray, elements.length, newElements.length);

    return newArray;
}

//[one, two, three]
//[one, two, three, four, five]
