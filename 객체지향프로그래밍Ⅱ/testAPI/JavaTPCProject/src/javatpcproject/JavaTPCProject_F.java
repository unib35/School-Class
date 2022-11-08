import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JavaTPCProject_F {
	JTextField address;
	JLabel resAddress, resX, resY, jibunAddress;
	JLabel imageLabel;
	
	public void initGUI() {
		JFrame frm = new JFrame("Map View");                    // ������ ����
		frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);     // �������� X Ŭ�� �� ����.
		Container c = frm.getContentPane();                     // JFrame ���� ����.
		
		imageLabel = new JLabel("��������");                    // JFrame ���� ���� ��ܿ� �� ��������
		JPanel pan = new JPanel();
		JLabel addressLbl = new JLabel("�ּ��Է�");             // JFrame ���� ���� ��ܿ� �� �ּ��Է�
		address = new JTextField(50);
		JButton btn = new JButton("Ŭ��");                      // JFrame ���� ������ �� Ŭ�� ��ư
		pan.add(addressLbl);
		pan.add(address);
		pan.add(btn);	
		btn.addActionListener(new NaverMap(this));              // pan�� ������ ��ư(btn) Ŭ�� �� ó���ϴ� �̺�Ʈ �ڵ鷯.
		
		JPanel pan1 = new JPanel();
		pan1.setLayout(new GridLayout(4, 1));                   // ���� �ϴ� �׸��� 4�� 1���� ����.
		resAddress = new JLabel("���θ�");                      // �׸��� 1�࿡ �� ���θ�
		jibunAddress = new JLabel("�����ּ�");                  // �׸��� 2�࿡ �� �����ּ�
		resX = new JLabel("�浵");                              // �׸��� 3�࿡ �� �浵
		resY = new JLabel("����");                              // �׸��� 4�࿡ �� ����
		pan1.add(resAddress);
		pan1.add(jibunAddress);
		pan1.add(resX);
		pan1.add(resY);
		
		c.add(BorderLayout.NORTH, pan);                         // ��� pan ����
		c.add(BorderLayout.CENTER, imageLabel);                 // ���� imageLabel ����
		c.add(BorderLayout.SOUTH, pan1);                        // �ϴ� pan1 ����
		
		frm.setSize(730, 660);
		frm.setVisible(true);
		
	}
	
	public static void main(String[] args) {
		new JavaTPCProject_F().initGUI();	
	}
}