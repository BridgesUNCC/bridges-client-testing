import bridges.base.CircSLelement;
import bridges.connect.Bridges;

public class csllist {

	public static void main(String[] args) throws Exception {

#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		bridges.set_title("A Circle Singly Linked List Example");
        bridges.set_description("This example shows five nodes. Each node is linked only to its child node. "
				+	"Colors are: A green node with a yellow link size 12, a blue node with a magenta link size 9, "
				+	"a magenta node with a blue link size 9, a red node with a magenta link size 11, and a yellow node with "
				+	"a red link size 15.");
				
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
#endif
		StudentInfo[] students = {
			new StudentInfo(
				"00000000000",
				"Gretel Chaney",
				"CS",
				"g.chaney@generated.com",
				"magenta",
				"blue",
				9.0
			),
			new StudentInfo(
				"00000000001",
				"Karol Soderman",
				"SIS",
				"k.soderman@generated.com",
				"magenta",
				"red",
				11.0
			),
			new StudentInfo(
				"00000000002",
				"Lamont Kyler",
				"BIO",
				"l.kyler@generated.com",
				"yellow",
				"green",
				12.0
			),
			new StudentInfo(
				"00000000003",
				"Gladys Serino",
				"CS", "g.serino@generated.com",
				"blue",
				"magenta",
				9.0
			),
			new StudentInfo("00000000004",
				"Starr Mcginn",
				"CS",
				"s.mcginn@generated.com",
				"red",
				"yellow",
				15.0)
		};

		CircSLelement<StudentInfo> head = new CircSLelement<StudentInfo>("", students[0]);
		CircSLelement<StudentInfo> current = head;

		for (int i = 1; i < students.length; i++) {
			current.setNext(new CircSLelement<StudentInfo>("", students[i]));

			//handle the last element
			if (i == students.length - 1) {
				//getting the last element
				current = current.getNext();

				//	point the last element to the first element,
				// 	so the list becomes circular.
				current.getNext().setNext(head);
			}

			//set the current element to be the next element
			current = current.getNext();
		}


		current = head;

		// add visual attributes
		do {
			current.setLabel(current.getValue().getStudentLabel());
			current.setColor(current.getValue().getFavoriteColor());

			current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours() * 0.3);

			current = current.getNext();
		}	while (current.getIdentifier() != head.getIdentifier());

		bridges.setDataStructure(head);
		bridges.visualize();
	}
}
