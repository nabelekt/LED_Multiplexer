# PCBWay Review
Note: Best viewed on GitHub

![PCBWay Logo](https://hackster.imgix.net/uploads/attachments/1033579/0x0_fQleAM915d.png?auto=compress%2Cformat&w=740&h=555&fit=max)

[PCBWay (pcbway.com)](https://pcbway.com) was kind enough to sponsor the order for my Stage 5 PCBs, fabrication and assembly, on the condition that I write a review here, so here are some details on my experience working with them:

One of the best things about working with PCBWay is the customer support and communication. In my experience, their support representatives have been very communicative throughout the whole process from ordering to inspection post-delivery. When you place an order, their first step is to review your order and let you know about any problems they notice. You may have to go back into your EDA software to adjust your design and resubmit your files. It's nice to have another set of eyes look at things from a production perspective. When PCBWay was getting ready to assemble by Stage 5b circuit, they weren't sure about the orientation of the LEDs – they knew which pins were the anode and cathode, but I didn't have polarity marked on my board, so they sent me an image by email to mark. (I corrected this in the CircuitMaker project for your sake):
![Stage 5 PCB Layout with LED Polarity Marked](https://hackster.imgix.net/uploads/attachments/1033450/screen_shot_2019-12-07_at_4_58_35_pm_xwU2Q6trqL.png?auto=compress%2Cformat&w=740&h=555&fit=max)

When ordering components from digikey.cn (Digikey's Chineese site), the SPDT-SW switch was not in stock. From this I learned that the availability for a particular part from DigiKey in the US does not necessarily reflect availability from DigiKey in China. PCBWay asked if I wanted to ship the part to them (and thus probably delay production), or solder it on myself. I choose the latter.

When assembly was complete, they sent me images for review:
![Images sent for vertification](https://hackster.imgix.net/uploads/attachments/1033455/img_20191113_084640_kZ80gUXECz.jpg?auto=compress%2Cformat&w=740&h=555&fit=max)
![Images sent for vertification](https://hackster.imgix.net/uploads/attachments/1033457/img_20191113_084645_x7uJ7dj76E.jpg?auto=compress%2Cformat&w=740&h=555&fit=max)
![Images sent for vertification](https://hackster.imgix.net/uploads/attachments/1033456/sw-prog_orientation_SEDJdB0UOV.jpg?auto=compress%2Cformat&w=740&h=555&fit=max)

I noted three things: (1) LED-R3C3 was not properly placed. I let them know about the issue. They verified that they understood the problem correctly and then corrected it. (2) In the second image, there appears to be some imperfection in the solder mask, maybe caused by a soldering iron. This wasn't present when I inspected the boards on delivery. (3) As shown in the third image, they made an educated guess on the orientation of SW-PROG and got it right. 

While board fabrication and shipping is quick (Stage 4 took 4.5 days from placing the order to delivery), assembly takes quite a bit longer than I would expect. As you can see from my order details in Step 2 above, build time was estimated at 18-20 days. Part of this time is the time it takes to ship the components from the supplier (DigiKey) to the production house (PCBWay). However, I would still expect quicker turnaround time. My order took 26 days from the time I placed it online to delivery in Colorado. In the future, for low quantity prototype production, I plan to assemble the boards myself as we did for Stage 5a. Note : After reading this, PCBWay mentioned to me that when it comes to assembly, "if you want to get it earlier, you can note your order as an urgent one."

I would also like to see lower assembly costs for single prototype boards. $30 to solder fewer than 30 (SMD and TH) parts to a board seems like a lot. I am guessing that they might assemble a quantity of one by hand and anything more than that my machine. For my same Stage 5 design, I can get 20 boards assembled for the same $30, but then the price jumps before coming back down:

![Assembly Costs](https://hackster.imgix.net/uploads/attachments/1033469/screen_shot_2019-12-09_at_7_28_49_pm_cBp2kqxC8n.png?auto=compress%2Cformat&w=740&h=555&fit=max)

When I ordered my boards, I expected to receive a solder stencil, but I did not. A solder stencil could have made Step 3 of Stage 5 a bit clearner and easier. When I asked PCBWay about this, I was told: "when the assembly service completed, we uaually do not send the solder stencil to customer unless you have special needs... if you really want solder stencil, for your next order, we can send it to you with your special need."

As for quality, I was very pleased. The fabrication of both the Stage 4 and Stage 5 boards left me nothing to complain about. Assembly for Stage 5b was equally satisfying.

All in all, I was pleased with my PCBWay experience.
