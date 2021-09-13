import java.util.Arrays;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");
    }

    public int deepSearch(int[] arr, int position, int tarjet, int n_child){
        if(arr[position] == tarjet) {
            return position;
        } else {
            while(!isEmpty(arr, position)){
                int e = rules(position, n_child);
                if(e == -1) {
                    return -1;
                } 
                if(e == tarjet) {
                    deepSearch(arr, position, tarjet, n_child);
                }
                    
                return position;
            }
        }
    }

    public int ampSearch(int[] arr, int tarjet, int n_child) {
        int[] l_arr = arr;
        int top = 0;
        while(!success(arr, tarjet) || !isEmpty(arr, top)) {
            int e = l_arr[0];
            pop(l_arr, top++);
            for(int i = 0; i < n_child; i++) {
                int n;
                n = rules(i, n_child);
                if(e == tarjet){
                    return e; //n????
                } else {
                    l_arr[i] = n;
                }
            }
        } return -1;
    }

    public boolean isEmpty(int[] arr, int top) {
        return top == arr.length-1;
    }

    public void pop(int[] arr, int top) {
        arr[top] = -1;
    }

    public boolean success(int[] arr, int tarjet, int position) {
        return arr[position] == tarjet;
    }

    public int rules(int position, int n_child){
        switch(position) {
            /** unimplemented method */
        }
        return 0;
    }
}
