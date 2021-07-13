package gui;

import code.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class GUI {
    JTextArea binary;
    JTextArea hamming;
    JTextArea trinary;
    JTextArea DNA;
    JTextArea bestDNA;
    JLabel SAV;
    JLabel bestPlan;
    JLabel bestSAV;
    Main main;
    String filePath= "";

    public static void main(String[] args) {
        new GUI(new Main()).createWindow();
    }

    public GUI(Main main){
        this.main = main;
    }

    private void createWindow() {
        JFrame frame = new JFrame("BioEncoder");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        createContent(frame);
        createUI(frame);
        frame.setSize(1000, 700);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    private void createUI(final JFrame frame) {
        JPanel panel = new JPanel();
        LayoutManager layout = new FlowLayout();
        panel.setLayout(layout);
        JButton selectButton = new JButton("ѡ�������ļ�");
        JButton confirmButton = new JButton("��ʼ����");
        final JLabel label = new JLabel();
        label.setText("��ǰѡ����ļ�Ϊ��(δѡ���ļ�)");
        selectButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser fileChooser = new JFileChooser();
                fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
                int option = fileChooser.showOpenDialog(frame);
                if (option == JFileChooser.APPROVE_OPTION) {
                    File f = fileChooser.getSelectedFile();
                    filePath = f.getPath();
                    label.setText("��ǰѡ����ļ�Ϊ��"+f.getPath());
                }
            }
        });
        confirmButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                calculate(filePath);
            }
        });
        panel.add(selectButton);
        panel.add(label);
        panel.add(confirmButton);
        frame.getContentPane().add(panel, BorderLayout.NORTH);
    }

    private void createContent(final JFrame frame) {
        JPanel panel = new JPanel();
        binary = new JTextArea(50,10);
        hamming= new JTextArea(50,10);
        trinary= new JTextArea(50,10);
        DNA= new JTextArea(50,10);
        bestDNA= new JTextArea(50,10);
        panel.setLayout(new GridLayout(13,1));
        panel.add(new JLabel("�ļ��Ķ����Ʊ�ʾ"));
        panel.add(binary);
        panel.add(new JLabel("�ļ��ĺ������ʾ"));
        panel.add(hamming);
        panel.add(new JLabel("���������������Ʊ�ʾ"));
        panel.add(trinary);
        panel.add(new JLabel("DNA����"));
        panel.add(DNA);
        panel.add(SAV = new JLabel("��ƥ���Ϊ����δ���㣩"));
        panel.add(bestPlan = new JLabel("���ű��뷽������δ���㣩"));
        panel.add(bestSAV = new JLabel("������ƥ��ȣ���δ���㣩"));
        panel.add(new JLabel("���ű����µ�DNA����"));
        panel.add(bestDNA);
        frame.getContentPane().add(panel, BorderLayout.CENTER);
    }

    public void calculate(String path){
        String bin = main.LoadFile(path);
        binary.setText(bin);
        bin = main.HammingEncode(bin);
        hamming.setText(bin);
        String tri = main.TriEncode(bin);
        trinary.setText(tri);
        String dna = main.BioEncode(tri);
        DNA.setText(dna);
        int sav = main.getSAV(dna);
        SAV.setText("��ƥ���Ϊ��"+sav);
        main.PrintSAV(dna);
        int[] order = main.getBestOrder(tri);
        String plan = main.getPlan(order);
        int bestsav = main.calculateSAV(tri,order);
        bestPlan.setText("���ű��뷽����"+plan);
        bestSAV.setText("������ƥ��ȣ�"+bestsav);
        String bestdna = main.bioEncode(tri,main.getTransTable(order));
        bestDNA.setText(bestdna);
        System.out.println("update");
    }

}
