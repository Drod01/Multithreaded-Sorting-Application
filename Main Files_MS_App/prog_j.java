import java.util.Arrays;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class ThreadArgs {
    int[] array;
    int size;

    public ThreadArgs(int[] array, int size) {
        this.array = array;
        this.size = size;
    }
}

public class MultithreadedSortingApp {
    public static double calculateAverage(int[] array, int size) {
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += array[i];
        }
        return sum / size;
    }

    public static void insertionSort(int[] array, int size) {
        // Implementation of insertion sort
        // ...
    }

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java MultithreadedSortingApp <array_size>");
            System.exit(1);
        }

        int N = Integer.parseInt(args[0]);
        int[] array = new int[N];

        // Initialize and populate the array with random values
        // ...

        ExecutorService executor = Executors.newFixedThreadPool(3);
        int segmentSize = N / 2;

        for (int i = 0; i < 2; i++) {
            int[] segment = Arrays.copyOfRange(array, i * segmentSize, (i + 1) * segmentSize);
            ThreadArgs threadArgs = new ThreadArgs(segment, segmentSize);
            executor.submit(() -> {
                insertionSort(threadArgs.array, threadArgs.size);
                double avg = calculateAverage(threadArgs.array, threadArgs.size);
                System.out.printf("Sorting average: %.2f%n", avg);
            });
        }

        // Submit the merging task and calculate the overall average
        // ...

        executor.shutdown();
        try {
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // Print the sorted array and execution time
        // ...

    }
}