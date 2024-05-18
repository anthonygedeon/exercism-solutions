import java.util.Arrays;
import java.util.stream.Collectors;

public class LogLevels {
    
    public static String message(String logLine) {
        String[] words = logLine.split("\s");
        String result = Arrays.stream(words).skip(1).collect(Collectors.joining(" "));
        return result.trim();
    }

    public static String logLevel(String logLine) {
        StringBuilder result = new StringBuilder();
        for (int i = 0; logLine.charAt(i) != ']'; i++) {
            if ((logLine.charAt(i) != '[') && Character.isAlphabetic(logLine.charAt(i))) {
                result.append(logLine.charAt(i));
            }
        }
        return result.toString().toLowerCase();
    }

    public static String reformat(String logLine) {
        return message(logLine) + ' ' + '(' + logLevel(logLine) + ')';
    }
}
