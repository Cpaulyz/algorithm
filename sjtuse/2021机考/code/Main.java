package code;

import java.io.*;

public class Main {
    /**
     * 1. read file as byte
     * 2. print phase1
     * 3. return binary string
     */
    public String LoadFile(String filepath) {
        StringBuilder res = new StringBuilder();
        int cnt0 = 0, cnt1 = 0; // 计数
        try {
            InputStream f = new FileInputStream(filepath);
            int b;
            while (true) {
                b = f.read();
                if (b == -1) {
                    break;
                }
                res.append(bytesToBinary(b));
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("文件不存在");
        }
        for (int i = 0; i < res.length(); i++) {
            if (res.charAt(i) == '0') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        System.out.println("Phase 1: " + cnt0 + " " + cnt1);
        return res.toString();
    }

    private String bytesToBinary(int b) {
        String res = "";
        for (int i = 0; i < 4; i++) {
            res += (b & (1 << (7 - i))) == 0 ? "0" : "1";
        }
        for (int i = 0; i < 4; i++) {
            res += (b & (1 << (3 - i))) == 0 ? "0" : "1";
        }
        return res;
    }

    /**
     * 1. return hamming code
     * 2. print phase2
     */
    public String HammingEncode(String binary) {
        StringBuilder res = new StringBuilder();
        int cnt0 = 0, cnt1 = 0; // 计数
        while (binary.length() % 7 != 0) {
            // 补全
            binary += "0";
        }
        for (int i = 0; i < binary.length() / 7; i++) {
            int[] d = new int[8]; // 原数字
            for (int j = 0; j < 7; j++) {
                // construct
                d[j + 1] = binary.charAt(7 * i + j) - '0';
            }
            int p1 = d[1] ^ d[2] ^ d[4] ^ d[5] ^ d[7];
            int p2 = d[1] ^ d[3] ^ d[4] ^ d[6] ^ d[7];
            int p3 = d[2] ^ d[3] ^ d[4];
            int p4 = d[5] ^ d[6] ^ d[7];
            int p5 = d[1] ^ d[2] ^ d[3] ^ d[4] ^ d[5] ^ d[6] ^ d[7] ^ p1 ^ p2 ^ p3 ^ p4;
            int[] tmpRes = {p1, p2, d[1], p3, d[2], d[3], d[4], p4, d[5], d[6], d[7], p5};
            for (int tmp : tmpRes) {
                if (tmp == 1) {
                    cnt1++;
                    res.append("1");
                } else {
                    cnt0++;
                    res.append("0");
                }
            }
        }
        System.out.println("Phase 2: " + cnt0 + " " + cnt1);
        return res.toString();
    }

    /**
     * 1. 将二进制编码为三进制
     * 2. 每9个二进制bit->6个三进制bit，不足九位补足0
     */
    public String TriEncode(String binary) {
        StringBuilder res = new StringBuilder();
        int[] cnt = new int[3]; // 计数
        while (binary.length() % 9 != 0) {
            // 补全
            binary += "0";
        }
        for (int i = 0; i < binary.length() / 9; i++) {
//            System.out.println("transfer:"+binary.substring(i*9,9+i*9));
            int tenTmp = 0; // 十进制
            // 先转为十进制中间结果
            for (int j = 0; j < 9; j++) {
                // construct
                int tmp = binary.charAt(9 * i + j) - '0';
                tenTmp += (tmp << (8 - j));
            }
//            System.out.println("ten:"+tenTmp);
            // 将十进制转为三进制
            StringBuilder triTmp = new StringBuilder();
            while (tenTmp >= 3) {
                int curBit = tenTmp % 3;
                cnt[curBit]++;
                triTmp.insert(0, curBit);
                tenTmp /= 3;
            }
            if(tenTmp>0){
                int curBit = tenTmp % 3;
                cnt[curBit]++;
                triTmp.insert(0, curBit);
            }
            while (triTmp.length()<6){
                cnt[0]++;
                triTmp.insert(0, "0");
            }
//            System.out.println("tri:"+triTmp.toString());
            res.append(triTmp);
        }
        System.out.println("Phase 3: " + cnt[0] + " " + cnt[1] + " " + cnt[2]);
        return res.toString();
    }

    /**
     * 1. 第一个字符和后面字符不同
     * 2. 返回DNA编码后的结果
     * 3. 输出ATCG统计
     * 4. 输出到文件 ./DNA.txt
     */
    public String BioEncode(String trinary){
        int[] cnt =new int[4];
        int[][] transTable = new int[4][];
        transTable[0] = new int[]{1,2,3};
        transTable[1] = new int[]{2,3,0};
        transTable[2] = new int[]{3,0,1};
        transTable[3] = new int[]{0,1,2};
//        transTable[0] = new int[]{2,1,3};
//        transTable[1] = new int[]{3,2,0};
//        transTable[2] = new int[]{1,0,3};
//        transTable[3] = new int[]{2,1,0};
        String res = bioEncode(trinary,transTable);
        for (int i = 0; i < res.length(); i++) {
            switch (res.charAt(i)){
                case 'A':
                    cnt[0]++;
                    break;
                case 'T':
                    cnt[1]++;
                    break;
                case 'C':
                    cnt[2]++;
                    break;
                case 'G':
                    cnt[3]++;
                    break;
            }
        }
        System.out.println("Phase 4: " + cnt[0] + " " + cnt[1] + " " + cnt[2]+ " " + cnt[3]);
        FileWriter.write("./DNA.txt",res);
        return res;
    }

    public String bioEncode(String trinary,int[][] transTable){
        // 表驱动
        // 0-A
        // 1-T
        // 2-C
        // 3-G
        StringBuilder res = new StringBuilder();
        String[] dna = {"A","T","C","G"};
        int status = trinary.charAt(0)-'0';
        res.append(dna[status]);
        for (int i = 1; i < trinary.length(); i++) {
            status = transTable[status][trinary.charAt(i)-'0'];
            res.append(dna[status]);
        }
        return res.toString();
    }

    /**
     * 输出自匹配度
     * 随便O(n2)先做吧。。。
     * @param dna DNA String
     */
    public void PrintSAV(String dna){
        System.out.println("Phase 5: SAV = " + getSAV(dna));
    }

    public int getSAV(String dna){
        int res = 0;
        for (int i = 0; i < dna.length(); i++) {
            //在第i个字符后面做折叠
            int tmp = 0;
            int len = (i+1)>(dna.length()-i-1)?(dna.length()-i-1):(i+1); // 只需要遍历少的次数
            if(len>res){
                for (int j = 0; j < len; j++) {
                    if(dnaStatus(dna.charAt(i-j))+dnaStatus(dna.charAt(i+j+1))==0){
                        tmp++;
                    }
                }
                res = res>tmp?res:tmp;
            }
            // 在第i个字符做折叠
            tmp = 0;
            if(len>res){
                len = (i)>(dna.length()-i-1)?(dna.length()-i-1):(i); // 只需要遍历少的次数
                for (int j = 0; j < len; j++) {
                    if(dnaStatus(dna.charAt(i-j-1))+dnaStatus(dna.charAt(i+j+1))==0){
                        tmp++;
                    }
                }
                res = res>tmp?res:tmp;
            }
        }
        return res;
    }

    private int dnaStatus(char c){
        // A=-1,T=1,C=-2,G=2
        int res = 0;
        switch (c){
            case 'A':
                res = 1;
                break;
            case 'T':
                res = -1;
                break;
            case 'C':
                res = 2;
                break;
            case 'G':
                res = -2;
                break;
        }
        return res;
    }

    public void BestEncodingPlan(String trinary){
        int res = Integer.MAX_VALUE;
        String bestPlan = "";
        int[][] orders =  {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
        int[] orderSelect = new int[4];
        for (int i = 0; i < orders.length; i++) {
            orderSelect[0] = i;
            for (int j = 0; j < orders.length; j++) {
                orderSelect[1] = j;
                for (int k = 0; k < orders.length; k++) {
                    orderSelect[2] = k;
                    for (int l = 0; l < orders.length; l++) {
                        orderSelect[3] = l;
                        int tmp = calculateSAV(trinary,orderSelect);
                        if(tmp<res){
                            res= tmp;
                            bestPlan = getPlan(orderSelect);
//                            System.out.println(tmp);
//                            System.out.println(bestPlan);
                        }else if(tmp==res){
                            // 找字典序小的
                            String tmpPlan = getPlan(orderSelect);
                            if(bestPlan.compareTo(tmpPlan)>0){
                                 bestPlan =  tmpPlan;
                            }
//                            System.out.println(tmp);
//                            System.out.println(tmpPlan);
                        }
                    }
                }
            }
        }
        String output = "Phase 6: Best SAV = "+res+"; "+bestPlan;
        System.out.println(output);
        FileWriter.write("./Best.txt",output);
    }

    public int[] getBestOrder(String trinary){
        int res = Integer.MAX_VALUE;
        int[] bestOrder = new int[4];
        String bestPlan = "";
        int[][] orders =  {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
        int[] orderSelect = new int[4];
        for (int i = 0; i < orders.length; i++) {
            orderSelect[0] = i;
            for (int j = 0; j < orders.length; j++) {
                orderSelect[1] = j;
                for (int k = 0; k < orders.length; k++) {
                    orderSelect[2] = k;
                    for (int l = 0; l < orders.length; l++) {
                        orderSelect[3] = l;
                        int tmp = calculateSAV(trinary,orderSelect);
                        if(tmp<res){
                            res= tmp;
                            bestPlan = getPlan(orderSelect);
                            bestOrder = orderSelect.clone();
                        }else if(tmp==res){
                            // 找字典序小的
                            String tmpPlan = getPlan(orderSelect);
                            if(bestPlan.compareTo(tmpPlan)>0){
                                bestPlan =  tmpPlan;
                                bestOrder = orderSelect.clone();
                            }
                        }
                    }
                }
            }
        }
        return bestOrder;
    }

    public String getPlan(int[] orderSelect){
        int[][] orders =  {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
        StringBuilder res = new StringBuilder();
        String[] dna = {"A","T","C","G"};
        int[][] transTable = new int[4][];
        transTable[0] = new int[]{1,2,3};
        transTable[1] = new int[]{2,3,0};
        transTable[2] = new int[]{3,0,1};
        transTable[3] = new int[]{0,1,2};
        for (int i = 0; i < orderSelect.length;i++) {
            res.append(dna[i]+": ");
            for (int j = 0; j < 3; j++) {
                int index = transTable[i][orders[orderSelect[i]][j]];
                res.append(dna[index]);
            }
            res.append(", ");
        }
        return res.toString().substring(0,res.length()-2);
    }

    public int calculateSAV(String trinary,int[] orderSelect){
        int[][] newTransTable = getTransTable(orderSelect);
        String dna = bioEncode(trinary,newTransTable);
        return getSAV(dna);
    }

    public int[][] getTransTable(int[] orderSelect){
        int[][] orders =  {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,1,0},{2,0,1}};
        int[][] transTable = new int[4][];
        transTable[0] = new int[]{1,2,3};
        transTable[1] = new int[]{2,3,0};
        transTable[2] = new int[]{3,0,1};
        transTable[3] = new int[]{0,1,2};
        int[][] newTransTable = new int[4][3];
        for (int i = 0; i < orderSelect.length;i++) {
            for (int j = 0; j < 3; j++) {
                newTransTable[i][j] = transTable[i][orders[orderSelect[i]][j]];
            }
        }
        return newTransTable;
    }


    public static void main(String[] args) throws IOException {
        Main main = new Main();
        System.out.println("Please enter the input path:");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String path  = br.readLine();
//        String binary = main.LoadFile("C:\\Users\\admin\\Desktop\\推免\\上交\\机考\\BioEncoding-Handout\\sample.txt");
//        String binary = main.LoadFile("C:\\Users\\admin\\Desktop\\推免\\上交\\机考\\BioEncoding-Handout\\large.jpg");
        String binary = main.LoadFile(path);
        binary = main.HammingEncode(binary);
        String trinary = main.TriEncode(binary);
        String dna = main.BioEncode(trinary);
        main.PrintSAV(dna);
        main.BestEncodingPlan(trinary);
    }
}
