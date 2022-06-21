#include <vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkTextActor.h>


int main(int argc, char **argv) {
  auto textActor = vtkSmartPointer<vtkTextActor>::New();
  textActor->SetInput("Hello World");

  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(textActor);
  renderer->ResetCamera();

  auto interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

  auto renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  renderWindow->SetInteractor(interactor);

  interactor->Start();

  return 0;
}