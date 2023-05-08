import yolov7
model = yolov7.load('yolov7.pt')
model.conf = 0.25  # NMS confidence threshold
model.iou = 0.45  # NMS IoU threshold
model.classes = None  # (optional list) filter by class

# set image
imgs = 'inference/images'

# perform inference
results = model(imgs)

# inference with larger input size and test time augmentation
results = model(img, size=1280, augment=True)

# parse results
predictions = results.pred[0]
boxes = predictions[:, :4] # x1, y1, x2, y2
scores = predictions[:, 4]
categories = predictions[:, 5]

# show detection bounding boxes on image
results.show()