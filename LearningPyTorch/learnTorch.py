import torch
from torch import nn
from torch.utils.data import Dataset
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor
import matplotlib.pyplot as plt

# Loading the data
training_data = datasets.MNIST(
        root = "MNISTset",
        train = True,
        download = False,
        transform = ToTensor()
        )
test_data = datasets.MNIST(
        root = "MNISTset",
        train = False,
        download = False,
        transform = ToTensor()
        )

# Hyper-parameters of the model
batch_size = 32
learning_rate = 1e-3
num_epochs = 5

# Creating the data loaders
training_dl = DataLoader(training_data, batch_size = batch_size, shuffle = True)
test_dl = DataLoader(test_data, batch_size = batch_size, shuffle = True)

# testing out a mini-batch visualization
# x_train, y_train = next(iter(test_dl))
# plt.imshow(torch.cat([item for item in x_train.squeeze().reshape(8, 28*4,28)], dim = 1))
# plt.show()

# Writing the network class
class ANN(nn.Module):
    def __init__(self):
        super(ANN, self).__init__()
        self.flatten = nn.Flatten()
        self.layers = nn.Sequential(
                nn.Linear(28*28, 100),
                nn.Sigmoid(),
                nn.Linear(100, 16),
                nn.Sigmoid(),
                nn.Linear(16, 10),
                nn.Sigmoid()
                )
    def forward(self, x):
        x = self.flatten(x)     # flatten the incoming image
        pred = self.layers(x)   # propagate the input in a forward pass
        ret = torch.argmax(pred, dim = 1)
        print("Type of model output", type(ret), ", Type of thing in ret: ", type(ret[0]),"shape: ", ret.shape, "ret: ", ret)
        return ret

# Creating a network
model = ANN()#.to('cpu')
loss_fn = nn.MSELoss()
optimizer = torch.optim.SGD(model.parameters(), lr = learning_rate)

X, y = next(iter(training_dl))
print("Label type: ", type(y), "Shape: ", y.shape, "Label: ", y)
pred = model(X)
print("Label for data: ", y)
print(pred.shape, pred)
loss = loss_fn(pred, y)
print(loss)

# Training loop (for one epoch)
# def training_loop(dataloader, model, loss_fn, optimizer):
    # size = len(dataloader.dataset)
    # # for each mini-batch
    # for batchNum, (X,y) in enumerate(dataloader):
        # # compute the prediction and loss
        # pred = model(X)
        # loss = loss_fn(pred, y)

        # # Backpropagate to get derivatives of loss wrt parameters
        # optimizer.zero_grad()       # set optimizer gradients to zero
        # loss.backward()             # the actual backprop step
        # optimizer.step()

        # # Print the progress
        # if batchNum % 100 == 0:
            # loss, exNum = loss.item(), batchNum * len(X)
            # print("Loss: ", loss," Examples trained: ", current,"/", size)

# def test_loop(dataloader, model, loss_fn):
    # size = len(dataloader.dataset)
    # num_batches = len(dataloader)
    # test_loss, numCorrect = 0, 0

    # with torch.no_grad():   # we don't need autodiff for these steps
        # for X, y in dataloader:
            # pred = model(X)
            # test_loss += loss_fn(pred, y).item()
            # numCorrect += (pred.argmax(1) == y).type(torch.float).sum().item()

        # test_loss /= num_batches
        # numCorrect /= size
        # print("Test error: \nAccuracy: ", numCorrect * 100, ", Avg loss: ", test_loss)

# for epoch in range(num_epochs):
    # print("Epoch #", epoch,"\n-----------------------------------------")
    # training_loop(training_dl, model, loss_fn, optimizer)
    # test_loop(test_dl, model, loss_fn)
print("Done!")

