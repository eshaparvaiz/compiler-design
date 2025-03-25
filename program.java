#Java Program to Verify if an Entered String is a Valid Identifier in Java


import java.util.*;

public class Main {
    static Set<String> keywords = new HashSet<>(Arrays.asList(
        "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const", "continue",
        "default", "do", "double", "else", "enum", "extends", "final", "finally", "float", "for", "goto", "if",
        "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "package", "private",
        "protected", "public", "return", "short", "static", "strictfp", "super", "switch", "synchronized", "this",
        "throw", "throws", "transient", "try", "void", "volatile", "while"));

    static boolean isValidJavaIdentifier(String s) {
        if (keywords.contains(s) || s.isEmpty() || !Character.isJavaIdentifierStart(s.charAt(0))) return false;
        for (char c : s.toCharArray()) if (!Character.isJavaIdentifierPart(c)) return false;
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        System.out.println(isValidJavaIdentifier(s) ? "Valid" : "Invalid");
    }
}
