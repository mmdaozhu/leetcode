/*
解体思路：
    算法：BFS
    在set中找考察字符串的相邻字符串（只有一个字符不同），并加入队列中。
    依次考察队列中的字符串。
时间复杂度分析：O(n)
*/

import java.util.*;

public class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }
        int depth = 0;
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);

        while (!queue.isEmpty()) {
            depth++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String head = queue.poll();
                if (head.equals(endWord)) {
                    return depth;
                }

                Iterator<String> iterator = wordList.iterator();
                while (iterator.hasNext()) {
                    String word = iterator.next();
                    if (isChangeOneTime(head, word)) {
                        iterator.remove();
                        queue.add(word);
                    }
                }
            }
        }
        return 0;
    }

    private boolean isChangeOneTime(String left, String right) {
        int count = 0;
        for (int i = 0; i < left.length(); i++) {
            if (left.charAt(i) != right.charAt(i)) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return count == 1 ? true : false;
    }

    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void test1() {
        String beginWord = "hit";
        String endWord = "cog";
        List<String> wordList = new ArrayList<>(Arrays.asList("hot", "dot", "dog", "lot", "log", "cog"));

        Solution s = new Solution();
        assert s.ladderLength(beginWord, endWord, wordList) == 5;
    }

    private static void test2() {
        String beginWord = "hit";
        String endWord = "cog";
        List<String> wordList = new ArrayList<>(Arrays.asList("hot", "dot", "dog", "lot", "log"));

        Solution s = new Solution();
        assert s.ladderLength(beginWord, endWord, wordList) == 0;
    }
}
