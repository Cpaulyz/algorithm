package code;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;

/**
 * ��������ļ�
 */
public class FileWriter {
    public static void write(String filePath,String text){
        try {

            File f = new File(filePath);
            FileOutputStream fop = new FileOutputStream(f);
            // ����FileOutputStream����,�ļ������ڻ��Զ��½�
            OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8");
            // ����OutputStreamWriter����,��������ָ������,Ĭ��Ϊ����ϵͳĬ�ϱ���,windows����gbk
            writer.append(text);
            writer.close();
            // �ر�д����,ͬʱ��ѻ���������д���ļ�,���������ע�͵�
            fop.close();
            // �ر������,�ͷ�ϵͳ��Դ
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
