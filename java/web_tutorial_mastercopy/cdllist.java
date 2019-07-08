import bridges.base.CircDLelement;
import bridges.connect.Bridges;

public class cdllist {

	public static void main(String[] args) throws Exception {


#if TESTING

		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);

		bridges.setTitle("A Circular Doubly Linked List Example");
		bridges.setDescription("This example shows five nodes each linked to their parent and child node. "
				+	"Colors are: Magenta node with blue links size 9, Red node with magenta links size 11, blue node with magenta links size 9, "
				+	"yellow node with red links size 15, and green node with yellow links size 12.");

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

		//initializing all student elements
		CircDLelement<StudentInfo> head = null;

		for (int i = 0; i < students.length; i++) {
			if (i > 0)
				head = insertFront(head, new CircDLelement<StudentInfo>("", students[i]));
			else
				head = new CircDLelement<StudentInfo>("", students[i]);
		}

		CircDLelement<StudentInfo> current = head;
		// add visual attributes
		do {
			current.setLabel(current.getValue().getStudentLabel());
			current.setColor(current.getValue().getFavoriteColor());

			current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours() * .2);

			current.getLinkVisualizer(current.getPrev()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getPrev()).setThickness(current.getValue().getStudentCreditHours() * .2);

			current = current.getNext();
		}	while (current != head);

		bridges.setDataStructure(head);

		bridges.visualize();
	}

	public static CircDLelement<StudentInfo> insertFront(
		CircDLelement<StudentInfo> tailElement,
		CircDLelement<StudentInfo> newElement) {
		CircDLelement<StudentInfo> tailNextElement = tailElement.getNext();

		newElement.setNext(tailNextElement);
		newElement.setPrev(tailElement);

		tailNextElement.setPrev(newElement);
		tailElement.setNext(newElement);

		return tailElement;
	}
}
