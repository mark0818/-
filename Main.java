import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        int modeNum, num;
        List<Item> itemList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        System.out.println("------컬랙션 사용 예------");

        while(true){
            System.out.print("아이탬 추가(1) / 출력(2) / 종료(0) : ");
            modeNum = scanner.nextInt();
            if(modeNum == 1){
                do {
                    System.out.print("이름 : ");
                    String name = scanner.next();
                    System.out.print("가격 : ");
                    int price = scanner.nextInt();
                    Item item = new Item(name, price);
                    itemList.add(item);
                    System.out.print("한번더?(1) / 종료(0) : ");
                    num = scanner.nextInt();
                } while(num == 1);
            } else if (modeNum == 2) {
                for (Item i : itemList) {
                    System.out.printf("%s / %d\n",
                            i.getName(), i.getPrice());
                }
            } else if(modeNum == 3){
                    System.out.print("삭제할 아이템 이름: ");
                    String name = scanner.next();
                    for (Item i: itemList){
                        if(name.equals(i.getName())){
                            itemList.remove(i);
                            break;
                        }
                    }
            }else if (modeNum == 0) {
                System.out.println("프로그램을 종료합니다.");
                return;
            } else {
                System.out.println("1, 2, 3번 중 선택");
            }
        }


    }
}