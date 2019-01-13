import bridges.base.CircSLelement;
import bridges.connect.Bridges;

public class csllist {

	public static void main(String[] args) throws Exception {


#if TESTING
		Bridges bridges = new Bridges(Integer.parseInt(args[0]), args[1], args[2]);
		bridges.setServer(args[3]);
#else
		Bridges bridges = new Bridges(YOUR_ASSIGNMENT_NUMBER, "YOUR_USER_ID", 
										"YOUR_API_KEY");
#endif

		bridges.setTitle("A Circle Singly Linked List Example");
        bridges.setDescription("In this example the user has built an array of students and their information including, student number, "
                +   "name, major, email address, favorite color, disliked color, and credit hours. A for loop is used to iterate through this array "
                +   "creating and linking a list of CircDLelements. Note that each element is linked once and only to the next element in the list. "
				+   "After the list is created, a do-while loop is used to alter the visual "
                +   "attributes of the data using the students color preferences and number of credits.");

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
			current.getVisualizer().setColor(current.getValue().getFavoriteColor());

			current.getLinkVisualizer(current.getNext()).setColor(current.getValue().getDislikeColor());
			current.getLinkVisualizer(current.getNext()).setThickness(current.getValue().getStudentCreditHours() * 0.3);

			current = current.getNext();
		}	while (current.getIdentifier() != head.getIdentifier());

		bridges.setDataStructure(head);
		bridges.visualize();
	}
}
