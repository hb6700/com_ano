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
		// 도 = 256Hz
		// 레 = 도 * 9/8 = 288Hz
		// 미 = 레 * 10/9 = 320Hz
		// 파 = 미 * 16/15 = 341.3Hz
		// 솔 = 파 * 9/8 = 384Hz
		// 라 = 솔 * 10/9 = 426.6Hz
		// 시 = 라 * 9/8 = 480Hz
		// 도 = 시 * 16/15 = 512Hz (= 처음 도의 2배)
		// 2배 = 높은음, 1/2배 = 낮은음

		25         static void Main(string[] args)
			26         {
			27             new Program();
			28         }
		29         public Program() {
			30             String data = "솔솔라라솔솔미솔솔미미레솔솔라라솔솔미솔미레미도";
			31             for (int i = 0; i < data.Length; i++) {
				32                 tone(data[i].ToString());
				33
			}
			34
		}
		35         public void tone(String data) {
			36             int hrz = 0;
			37             switch (data) {
				38                 case "도": hrz = 256; break;
				39                 case "레": hrz = 288; break;
				40                 case "미": hrz = 320; break;
				41                 case "파": hrz = 341; break;
				42                 case "솔": hrz = 384; break;
				43                 case "라": hrz = 426; break;
				44                 case "시": hrz = 480; break;
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

출처: http://nowonbun.tistory.com/161?category=507116 [명월 일지]