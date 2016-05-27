using System;
using System.Collections.Generic;
using System.Collections;
using System.IO;
using System.Linq;

class Solution {
    static void Main(String[] args) {
        int t = Convert.ToInt32(Console.ReadLine());
        while (t > 0){
            string[] entry = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(entry[0]);
            int k = Convert.ToInt32(entry[1]);
            ArrayList candidates = new ArrayList();
            int min = 1;
            while (min <= n) min = (min << 1) + 1;
            min = min >> 1;
            for (int i = min; i <= n; i++) candidates.Add(i);
            int max = 0;
            for(int i = k - 1; i > 0; i--){
                foreach (int candidate in candidates) {
                    int val = i & candidate;
                    if (i < candidate && val > max) max = val;
                    if (max == i) break;
                }
                if (max == i) break;
            }
            Console.WriteLine(max);
            t--;
        }
    }
}
