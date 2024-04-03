using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;

namespace Test20121006
{
	class Program
	{
		[DllImport("KERNEL32.DLL")]
		public extern static void Beep(int freq, int dur);
		// �� = 256Hz
		// �� = �� * 9/8 = 288Hz
		// �� = �� * 10/9 = 320Hz
		// �� = �� * 16/15 = 341.3Hz
		// �� = �� * 9/8 = 384Hz
		// �� = �� * 10/9 = 426.6Hz
		// �� = �� * 9/8 = 480Hz
		// �� = �� * 16/15 = 512Hz (= ó�� ���� 2��)
		// 2�� = ������, 1/2�� = ������

		25         static void Main(string[] args)
			26         {
			27             new Program();
			28         }
		29         public Program() {
			30             String data = "�ֶּ��̷ֹֹּּ̼̹��ֶּ��̷ֹֹּ̼��̵�";
			31             for (int i = 0; i < data.Length; i++) {
				32                 tone(data[i].ToString());
				33
			}
			34
		}
		35         public void tone(String data) {
			36             int hrz = 0;
			37             switch (data) {
				38                 case "��": hrz = 256; break;
				39                 case "��": hrz = 288; break;
				40                 case "��": hrz = 320; break;
				41                 case "��": hrz = 341; break;
				42                 case "��": hrz = 384; break;
				43                 case "��": hrz = 426; break;
				44                 case "��": hrz = 480; break;
				45
			}
			46             Beep(hrz, 500);
			47
		}
		48
	}
	49
}
50

��ó: http://nowonbun.tistory.com/161?category=507116 [��� ����]