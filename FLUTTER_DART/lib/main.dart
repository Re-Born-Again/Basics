import 'package:flutter/material.dart';
import 'package:http/http.dart';

var sessionId = '';

void main() {
  runApp(const Myapp());
}

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {
  var regNo = TextEditingController();
  var dob = TextEditingController();
  var captcha = TextEditingController();
  var isLoading = true;

  @override
  void initState() {
    super.initState();
    setCookies();
  }

  Future<void> setCookies() async {
    final resp = await get(Uri.parse('https://webstream.sastra.edu/sastrapwi'));
    sessionId = resp.headers['Set-Cookies'] ?? '';
  }

  Future<void> submit() async {
    final resp =
        await post(Uri.parse('https://webstream.sastra.edu/sastrapwi'), body: {
      'txtRegNumber': regNo.text,
      'txtPwd': dob.text,
      'txtPA': '1',
      'answer': captcha.text,
    });
    if (resp.isRedirect) {
      await Navigator.of(context)
          .pushReplacement(MaterialPageRoute(builder: (_) => const Myapp()));
    }
  }

  @override
  Widget build(BuildContext context) {
    return isLoading
        ? Center(child: CircularProgressIndicator())
        : Scaffold(
            appBar: AppBar(title: Text("Login page")),
            body: Column(
              children: [
                Text('Reg no'),
                TextField(controller: regNo),
                Text('Reg no'),
                TextField(controller: regNo),
                Text('Reg no'),
                Image.network(
                    'https://webstream.sastra.edu/sastrapwi/stickyImg?ms=${DateTime.now().millisecond}'),
                TextField(controller: regNo),
                ElevatedButton(
                  onPressed: submit,
                  child: Text("Submit"),
                ),
              ],
            ));
  }
}

class Myapp extends StatelessWidget {
  const Myapp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      home: Home(),
    );
  }
}

class Home extends StatefulWidget {
  const Home({super.key});

  @override
  State<Home> createState() => _HomeState();
}

class _HomeState extends State<Home> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text(
            "Hello User!",
            style: TextStyle(color: Colors.white),
          ),
          backgroundColor: Colors.black,
        ),
        backgroundColor: Colors.black,
        body: Padding(
          padding: const EdgeInsets.fromLTRB(10, 10, 10, 10),
          child: SingleChildScrollView(
            child: Column(
              // for making it in vertical scroll
              children: [
                HomeContainer(
                  content: "Academic\nDetails",
                  imglink:
                      'https://img.freepik.com/free-vector/elegant-red-background_1340-4770.jpg?size=626&ext=jpg&ga=GA1.1.1387024122.1708704045&semt=sph',
                  onTap: () {
                    Navigator.push(
                      context,
                      MaterialPageRoute(
                        builder: (context) => const Academic(),
                      ),
                    );
                  },
                ),
                HomeContainer(
                  content: "Register &\nEvents",
                  imglink:
                      'https://img.freepik.com/free-photo/abstract-grunge-decorative-relief-navy-blue-stucco-wall-texture-wide-angle-rough-colored-background_1258-28311.jpg?size=626&ext=jpg&ga=GA1.1.1387024122.1708704045&semt=sph',
                  onTap: () {},
                )
              ],
            ),
          ),
        ));
  }
}

class HomeContainer extends StatelessWidget {
  final String content;
  final String imglink;
  final VoidCallback onTap;
  const HomeContainer({
    super.key,
    required this.content,
    required this.imglink,
    required this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
        onTap: onTap,
        child: Column(
          children: [
            Container(
                decoration: BoxDecoration(
                  color: Colors.blue,
                  borderRadius: BorderRadius.circular(10),
                  image: DecorationImage(
                      image: NetworkImage(imglink), fit: BoxFit.cover),
                ),
                height: 130,
                width: 400,
                child: Center(
                  child: Text(
                    content,
                    style: const TextStyle(fontSize: 33, color: Colors.white),
                  ),
                )),
            const SizedBox(
              height: 15,
            )
          ],
        ));
  }
}

class Academic extends StatelessWidget {
  const Academic({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.black,
        leading: IconButton(
          icon: const Icon(
            Icons.arrow_back,
            color: Colors.white,
          ),
          onPressed: () {
            Navigator.pop(
                context); // Navigate back to the previous route (Home)
          },
        ),
      ),
      backgroundColor: Colors.black,
      body: Padding(
        padding: const EdgeInsets.fromLTRB(25, 10, 25, 10),
        child: RefreshIndicator(
          onRefresh: () async {},
          child: SingleChildScrollView(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    const Text(
                      "Academic Dashboard",
                      style: TextStyle(
                          color: Colors.white,
                          fontSize: 20,
                          fontWeight: FontWeight.w500),
                    ),
                    IconButton(
                      icon: const Icon(
                        Icons.refresh_outlined,
                        color: Colors.white,
                      ),
                      onPressed: () {},
                    )
                  ],
                ),
                const SizedBox(
                  height: 40,
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    AcademicGridItem(
                      icon: Icons.calendar_month_outlined,
                      title: 'View\nTimetable',
                      color: const Color.fromARGB(255, 255, 255, 255),
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const Timetable(),
                          ),
                        );
                      },
                    ),
                    AcademicGridItem(
                      icon: Icons.check_box_outlined,
                      title: 'View\nAttendance',
                      color: const Color.fromARGB(255, 0, 110, 110),
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const Attendance(),
                          ),
                        );
                      },
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    AcademicGridItem(
                      icon: Icons.add_chart_outlined,
                      title: 'View\nInternal marks',
                      color: const Color.fromARGB(255, 0, 110, 110),
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                    AcademicGridItem(
                      icon: Icons.grading_outlined,
                      title: 'View\nCGPA history',
                      color: Colors.white,
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    AcademicGridItem(
                      icon: Icons.list_alt_outlined,
                      title: 'View\nCourses',
                      color: Colors.white,
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                    AcademicGridItem(
                      icon: Icons.credit_card_outlined,
                      title: 'View\nFee payments',
                      color: const Color.fromARGB(255, 0, 110, 110),
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                  ],
                ),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    AcademicGridItem(
                      icon: Icons.av_timer_outlined,
                      title: 'View\nExam schedule',
                      color: const Color.fromARGB(255, 0, 110, 110),
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                    AcademicGridItem(
                      icon: Icons.attach_money_outlined,
                      title: 'View\nFee due',
                      color: Colors.white,
                      onTap: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                            builder: (context) => const UnderConstruction(),
                          ),
                        );
                      },
                    ),
                  ],
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}

class AcademicGridItem extends StatelessWidget {
  final IconData icon;
  final String title;
  final Color color;
  final VoidCallback onTap;
  const AcademicGridItem({
    super.key,
    required this.title,
    required this.color,
    required this.icon,
    required this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,
      child: Column(
        children: [
          Container(
            decoration: BoxDecoration(
              color: color,
              borderRadius: BorderRadius.circular(10),
            ),
            height: 160,
            width: 160,
            padding: const EdgeInsets.fromLTRB(20, 37, 20, 20),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Icon(
                  icon,
                  color: color == Colors.white ? Colors.black : Colors.white,
                ),
                const SizedBox(height: 8),
                Text(
                  title,
                  style: TextStyle(
                    color: color == Colors.white ? Colors.black : Colors.white,
                    fontSize: 17,
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ],
            ),
          ),
          const SizedBox(height: 25),
        ],
      ),
    );
  }
}

class UnderConstruction extends StatelessWidget {
  const UnderConstruction({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.black,
          leading: IconButton(
            icon: const Icon(
              Icons.arrow_back,
              color: Colors.white,
            ),
            onPressed: () {
              Navigator.pop(
                  context); // Navigate back to the previous route (Home)
            },
          ),
        ),
        backgroundColor: Colors.black,
        body: const Center(
          child: Column(mainAxisAlignment: MainAxisAlignment.center, children: [
            Text(
              "This Page is Under Construction!",
              style: TextStyle(
                color: Colors.white,
                fontSize: 20,
              ),
            ),
          ]),
        ));
  }
}

class Timetable extends StatelessWidget {
  const Timetable({super.key});

  @override
  Widget build(BuildContext context) {
    return DefaultTabController(
      length: 6, // no tabs
      initialIndex: 0, // when open which tab should be showed
      child: Scaffold(
        appBar: AppBar(
          backgroundColor: Colors.black,
          title: const Text(
            'Timetable',
            style: TextStyle(
                color: Colors.white, fontWeight: FontWeight.w500, fontSize: 18),
          ),
          leading: IconButton(
            icon: const Icon(
              Icons.arrow_back,
              color: Colors.white,
            ),
            onPressed: () {
              Navigator.pop(
                  context); // Navigate back to the previous route (Home)
            },
          ),
          bottom: PreferredSize(
            preferredSize:
                const Size.fromHeight(35), // Adjust the height of the TabBar
            child: SizedBox(
              height: 28, // to change the height of the tab indicator
              child: TabBar(
                padding: const EdgeInsets.only(left: 20, right: 20),
                dividerColor: Colors.black,
                indicatorSize: TabBarIndicatorSize.tab,
                indicator: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(5),
                ),
                labelColor: const Color.fromARGB(255, 0, 110, 110),
                unselectedLabelColor: Colors.grey,
                labelStyle:
                    const TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                unselectedLabelStyle:
                    const TextStyle(fontSize: 18, fontWeight: FontWeight.w500),
                labelPadding: const EdgeInsets.symmetric(
                    horizontal: 8), // prevent fading at end
                tabs: const [
                  Tab(text: 'MON'),
                  Tab(text: 'TUE'),
                  Tab(text: 'WED'),
                  Tab(text: 'THU'),
                  Tab(text: 'FRI'),
                  Tab(text: 'SAT'),
                ],
              ),
            ),
          ),
        ),
        backgroundColor: Colors.black,
        body: const TabBarView(
          children: [
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
            Scroll(),
          ],
        ),
      ),
    );
  }
}

class Scroll extends StatelessWidget {
  const Scroll({super.key});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(top: 18),
      child: ListView(
        children: [
          for (int i = 0; i < 5; i++)
            Container(
              margin: const EdgeInsets.only(bottom: 18),
              height: 65,
              width: 350,
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: BorderRadius.circular(5),
              ),
              padding: const EdgeInsets.only(
                  left: 15, top: 11, right: 13, bottom: 11),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        'SUBJECT NAME',
                        style: TextStyle(
                            color: Colors.black,
                            fontSize: 15,
                            fontWeight: FontWeight.w500),
                      ),
                      Text(
                        'Faculty Name',
                        style: TextStyle(color: Colors.grey),
                      )
                    ],
                  ),
                  Text(
                    'Time',
                    style: TextStyle(
                        color: Color.fromARGB(255, 0, 110, 110),
                        fontSize: 16,
                        fontWeight: FontWeight.w500),
                  ),
                ],
              ),
            ),
          for (int i = 0; i < 5; i++)
            Container(
              margin: const EdgeInsets.only(bottom: 18),
              height: 65,
              width: 350,
              decoration: BoxDecoration(
                color: const Color.fromARGB(255, 0, 110, 110),
                borderRadius: BorderRadius.circular(5),
              ),
              padding: const EdgeInsets.only(
                  left: 15, top: 11, right: 13, bottom: 11),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.spaceBetween,
                children: [
                  Text(
                    'FREE HOUR',
                    style: TextStyle(
                        color: Colors.white,
                        fontSize: 15,
                        fontWeight: FontWeight.w500),
                  ),
                  Text(
                    'Time',
                    style: TextStyle(
                        color: Colors.white,
                        fontSize: 16,
                        fontWeight: FontWeight.w500),
                  ),
                ],
              ),
            ),
        ],
      ),
    );
  }
}

class Attendance extends StatelessWidget {
  const Attendance({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text(
            "Your Attendance",
            style: TextStyle(color: Colors.white),
          ),
          backgroundColor: Colors.black,
          leading: IconButton(
            icon: const Icon(
              Icons.arrow_back,
              color: Colors.white,
            ),
            onPressed: () {
              Navigator.pop(
                  context); // Navigate back to the previous route (Home)
            },
          ),
        ),
        backgroundColor: Colors.black,
        body: Padding(
          padding: const EdgeInsets.fromLTRB(10, 10, 10, 10),
          child: SingleChildScrollView(
            child: Column(
              // for making it in vertical scroll
              children: [
                AttendanceContainer(
                  name: "Subject1",
                  code: "S1",
                  total: 100,
                  present: 90,
                  absent: 10,
                  onTap: () {},
                ),
                AttendanceContainer(
                  name: "Subject2",
                  code: "S2",
                  total: 100,
                  present: 90,
                  absent: 10,
                  onTap: () {},
                ),
                AttendanceContainer(
                  name: "Subject3",
                  code: "S3",
                  total: 100,
                  present: 90,
                  absent: 10,
                  onTap: () {},
                ),
                AttendanceContainer(
                  name: "Subject4",
                  code: "S4",
                  total: 100,
                  present: 90,
                  absent: 10,
                  onTap: () {},
                ),
              ],
            ),
          ),
        ));
  }
}

class AttendanceContainer extends StatelessWidget {
  final String name;
  final String code;
  final int total;
  final int present;
  final int absent;
  final VoidCallback onTap;
  const AttendanceContainer({
    super.key,
    required this.name,
    required this.code,
    required this.total,
    required this.present,
    required this.absent,
    required this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: onTap,
      child: Column(
        children: [
          Container(
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(5),
            ),
            height: 200,
            width: double.infinity,
            padding: const EdgeInsets.fromLTRB(20, 37, 20, 20),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceBetween,
                  children: [
                    Text(
                      name,
                      style: const TextStyle(
                        color: Color.fromARGB(255, 0, 110, 110),
                        fontSize: 20,
                        fontWeight: FontWeight.w500,
                      ),
                    ),
                    Text(
                      code,
                      style: const TextStyle(
                        color: Color.fromARGB(255, 0, 110, 110),
                        fontSize: 17,
                        fontWeight: FontWeight.w500,
                      ),
                    ),
                  ],
                ),
                const SizedBox(height: 10),
                RichText(
                    text: TextSpan(children: [
                  const TextSpan(
                    text: "Total : ",
                    style: TextStyle(
                      color: Color.fromARGB(255, 0, 110, 110),
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                  TextSpan(
                    text: "$total hours",
                    style: const TextStyle(
                      color: Colors.black,
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                ])),
                const SizedBox(height: 10),
                RichText(
                    text: TextSpan(children: [
                  const TextSpan(
                    text: "Present : ",
                    style: TextStyle(
                      color: Color.fromARGB(255, 0, 110, 110),
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                  TextSpan(
                    text: "$present hours",
                    style: const TextStyle(
                      color: Colors.black,
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                ])),
                const SizedBox(height: 10),
                RichText(
                    text: TextSpan(children: [
                  const TextSpan(
                    text: "Absent : ",
                    style: TextStyle(
                      color: Color.fromARGB(255, 0, 110, 110),
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                  TextSpan(
                    text: "$absent hours",
                    style: const TextStyle(
                      color: Colors.black,
                      fontSize: 17,
                      fontWeight: FontWeight.w500,
                    ),
                  ),
                ])),
              ],
            ),
          ),
          const SizedBox(height: 25),
        ],
      ),
    );
  }
}
